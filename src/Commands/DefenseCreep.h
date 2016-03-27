#ifndef DefenseCreep_H
#define DefenseCreep_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

/*
 * This class encapsulates the script of commands to move up to a defense and stop.
 */
class DefenseCreep: public CommandGroup
{
public:
	/*
	 * Initializes a new instance of the DefenseCreep class. Initialize this class and add it to the scheduler
	 * to run this script of commands. We should only use this in autonomous mode.
	 */
	DefenseCreep();
};

#endif
