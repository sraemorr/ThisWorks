// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * This class encapsulates the elevator subsystem functions
 */
class Elevator: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	/*
	 * This is the physical pointer to the elevator solenoid.
	 */
	std::shared_ptr<DoubleSolenoid> solenoidElevator;
public:
	/*
	 * Initializes a new instance of the Elevator subsystem class.
	 */
	Elevator();

	/*
	 * This method will start the default command for the Elevator subsystem (MoveElevator)
	 */
	void InitDefaultCommand();

	/*
	 * Moves the elevator into the climbing position
	 */
	void Up();

	/*
	 * Moves the elevator into the retracted position
	 */
	void Down();

	/*
	 * Turns off the double solenoid
	 */
	void Off();
};

#endif
