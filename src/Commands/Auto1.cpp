#include "Auto1.h"
#include "MoveArm.h"
#include "MoveWheelieBar.h"
#include "TankDrive.h"

Auto1::Auto1()
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
	 * GAMEPLAN: In this autonomous, we are going to drop the arm and wheelie bar
	 * and drive backwards over the outer works
	 * This auto works on
	 * 	- Port-cullis
	 * 	- Low bar.
	 */

	// Lower the arm and the wheelie bar.
	printf("Moving the Arm and wheelie bar");
	AddSequential(new MoveArm(0.));
	AddSequential(new MoveWheelieBar(true, false));
	Wait(2.);

	// Drive for a few seconds backwards
	printf("Driving");
	AddSequential(new TankDrive(-.5));
	Wait(4.);

	// Get me off this ride!
	printf("STOP!");
	AddSequential(new TankDrive(0.));


}
