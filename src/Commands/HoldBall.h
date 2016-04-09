#ifndef HoldBall_H
#define HoldBall_H

#include "WPILib.h"
#include "../Robot.h"

class HoldBall: public Command
{
public:
	/*
	 * Initializes a new instance of the HoldBall class. Construct this if you want to
	 * just apply a little power to hold a ball in the collector.
	 */
	HoldBall();

	/*
	 * Called when this command is just starting, run once.
	 */
	void Initialize();

	/*
	 * Called when this command gets repeatedly called (and scheduled)
	 */
	void Execute();

	/*
	 * This is the boolean to call when this command should die.
	 */
	bool IsFinished();

	/*
	 * Called once upon ending.
	 */
	void End();

	/*
	 * Called when there is another command called that conflicts with this one.
	 */
	void Interrupted();
};

#endif
