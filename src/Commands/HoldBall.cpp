#include "HoldBall.h"

HoldBall::HoldBall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::collector.get());
}

// Called just before this Command runs the first time
void HoldBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HoldBall::Execute()
{
	Robot::collector->Hold();
}

// Make this return true when this Command no longer needs to run execute()
bool HoldBall::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void HoldBall::End()
{
	Robot::collector->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldBall::Interrupted()
{

}
