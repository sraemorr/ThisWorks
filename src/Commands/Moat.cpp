#include "Moat.h"

#include "MoveArm.h"
#include "MoveWheelieBar.h"
#include "TankDrive.h"
#include "HoldBall.h"

Moat::Moat()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	/*
	 * GAMEPLAN: In this autonomous, we are going to raise the arm to a
	 * carry position and drive over the defense.
	 * This auto works on
	 * 	- moat
	 * 	- rough terrain
	 * 	- uneven terrain
	 */
	AddParallel(new HoldBall(), 14);
	// Raise arm and wheelie bar
	AddSequential(new MoveArm(-50.), 3);
	AddSequential(new MoveArm(-50.), 3);
	AddSequential(new TankDrive(0), 3);
	// Let initialize do what it does best
	AddSequential(new MoveWheelieBar(false, false, true), 1);

	AddSequential(new TankDrive(.2), .1);
	AddSequential(new TankDrive(.3), .1);
	AddSequential(new TankDrive(.4), .1);
	AddSequential(new TankDrive(.5), .1);
	AddSequential(new TankDrive(.6), .1);
	// Drive for a few seconds forwards
	AddSequential(new TankDrive(.9), 2.2);

	// Get me off this ride!
	AddSequential(new TankDrive(0.1), 1);
}
