#ifndef Portcullis_H
#define Portcullis_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

/*
 * This class contains the command script that will run portcullis commands.
 */
class Portcullis: public CommandGroup
{
public:
	/*
	 * Initializes a new instance of the Portcullis class. Do not initialize this command in teleop.
	 */
	Portcullis();
};

#endif
