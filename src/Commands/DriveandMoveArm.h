#ifndef DriveandMoveArm_H
#define DriveandMoveArm_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "TankDrive.h"
#include "MoveArm.h"

class DriveandMoveArm: public CommandGroup
{
public:
	DriveandMoveArm(double, double, double);
};

#endif
