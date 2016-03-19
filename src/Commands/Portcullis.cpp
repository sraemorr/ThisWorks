#include "Portcullis.h"

#include "MoveArm.h"
#include "MoveWheelieBar.h"
#include "TankDrive.h"

Portcullis::Portcullis()
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

	// Lower the arm and the wheelie bar.
	AddSequential(new TankDrive(-.5), .5);
	AddSequential(new TankDrive(0.), 0);
	AddSequential(new MoveArm(0.), 3);
	AddSequential(new MoveArm(0.), 3);
	AddSequential(new MoveWheelieBar(true, true, true), 1);

	// Drive for a few seconds backwards
	AddSequential(new TankDrive(-.75), 3.5);

	// Get me off this ride!
	AddSequential(new TankDrive(0.1), 1);
}
