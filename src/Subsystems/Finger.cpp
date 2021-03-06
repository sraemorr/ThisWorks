// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Finger.h"
#include "../RobotMap.h"

#include "../Commands/MoveFinger.h"

Finger::Finger() : Subsystem("Finger") {
    solenoidFinger = RobotMap::fingerSolenoid;
}

void Finger::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

        SetDefaultCommand(new MoveFinger());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Finger::In() {
	solenoidFinger->Set(DoubleSolenoid::Value::kForward);
}

void Finger::Out() {
	solenoidFinger->Set(DoubleSolenoid::Value::kReverse);
}

void Finger::Off() {
	solenoidFinger->Set(DoubleSolenoid::Value::kOff);
}
