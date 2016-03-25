#ifndef Auto2_H
#define Auto2_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

/*
 * This class is a command group that represents the Moat autonomous.
 */
class Moat : public CommandGroup
{
public:
	/*
	 * Initializes a new instance of the Moat class. Construct this class to run the script
	 * for traversing the moat. Do not call this in teleoperated mode.
	 */
	Moat();
};

#endif
