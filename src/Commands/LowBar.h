#ifndef Auto1_H
#define Auto1_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

/*
 * This class is a command group that represents the LowBar autonomous.
 */
class LowBar: public CommandGroup
{
public:
	/*
	 * Initializes a new instance of the LowBar class. Construct this to add the low bar autonomous
	 * script to run in auto mode. Do not run this in teleop.
	 */
	LowBar();
};

#endif
