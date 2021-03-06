// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/MoveArm.h"

Arm::Arm() : PIDSubsystem("Arm", 0.05, 0.0, 0.0) {
    aRM_MOTOR_1 = RobotMap::armMotor1;
    aRM_MOTOR_2 = RobotMap::armMotor2;
    encoder = RobotMap::encoder;

	// ALWAYS SET A PID SYSTEM TO A START POINT!
	setPoint = 0;
	currentPosition = 0.;
	SetSetpoint(setPoint);

	for (int i = 0; i < 10; i++)
	{
		rollingAverage[i] = 90.;
	}

	Enable();
	isEnabled = true;

}

void Arm::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

        SetDefaultCommand(new MoveArm());
}

double Arm::ReturnPIDInput(){
	currentPosition = encoder->GetDistance();
	rollingAverage[rollingIndex] = currentPosition;

	rollingIndex = (rollingIndex + 1 < 10) ? rollingIndex + 1 : 0;

	// Do not return the rolling average, only return the last value for
	// crisp PID control.
	//printf("Current Arm Position %f\n", (encoder->GetDistance()));
	return currentPosition;
}

void Arm::UsePIDOutput(double output){
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);

	// Write speed to the motors. Note that we don't have to reverse them since we took care of that already.
	Drive((float)output);
}

void Arm::Drive(float speed) {

	// hold our position if PID is not enabled
	// else we want to know where we are and lock there
	// when we get out of override
	setPoint = isEnabled ? setPoint : ReturnPIDInput();

	// Cap the values at 1 so nothing strange happens
	if (speed > .5)
	{
		speed = .5;
	}

	// Limit lower values as well
	if (speed < -.3)
	{
		speed = -.3;
	}

	aRM_MOTOR_1->Set((float)speed);
	aRM_MOTOR_2->Set((float)speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arm::SetNewPosition(double newTarget, bool isRelative)
{
	//printf("set new target arm position %f\n", newTarget);
	if (!isRelative)
	{
		setPoint = newTarget;
	}

	SetSetpoint(newTarget);
}

void Arm::SetNewRelativePosition(Joystick * stick)
{
	double newPosition = setPoint -
			(8. * stick->GetRawAxis(1));


	// printf("new relative position %f\n", newPosition);

	this->SetNewPosition(newPosition, true);
}

double Arm::GetTarget()
{
	return setPoint;
}

void Arm::EnablePID(bool enable)
{
	if (enable && !isEnabled)
	{
		Enable();
		isEnabled = true;
	}
	else if(!enable && isEnabled)
	{
		Disable();
		isEnabled = false;
	}
	else
	{
		// DO NOTHING
	}
}

bool Arm::AtPosition()
{
	// average the last few samples and see what we have
	return abs(setPoint - GetRollingAverage()) < 5.;
}

double Arm::GetRollingAverage()
{
	double averaged = 0.0;
	for (int i = 0; i < 10; i++)
	{
		averaged += rollingAverage[i];
	}

	return averaged / 10.;
}
