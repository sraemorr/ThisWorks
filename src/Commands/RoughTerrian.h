#ifndef RoughTerrian_H
#define RoughTerrian_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

/*
 * This is the class that will run the rough terrain script for autonomous.
 */
class RoughTerrian: public CommandGroup
{
public:
	/*
	 * Initializes a new instance of the RoughTerrain class. Initialization and calling this class with the
	 * ->Start() method will run the RoughTerrain autonomous code. Do not call from Teleop.
	 */
	RoughTerrian();
};

#endif
