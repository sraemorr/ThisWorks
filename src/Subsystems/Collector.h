// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * This class contains the command implementing features of the collector.
 */
class Collector: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	/*
	 * This is the pointer to the speed controller that runs the collector.
	 */
	std::shared_ptr<SpeedController> collector;
public:
	/*
	 * Initializes a new instance of the Collector class.
	 */
	Collector();

	/*
	 * This method will initialize the default command that will be running the collector subsystem.
	 */
	void InitDefaultCommand();

	/*
	 * This method will run the collector to intake a ball.
	 */
	void In();

	/*
	 * This method will run the collector to spit out a ball.
	 */
	void Out();

	/*
	 * This method stops the collector.
	 */
	void Stop();

	/*
	 * This method will apply a little power to hold the ball in the collector.
	 * Called only in autonomous.
	 */
	void Hold();
};

#endif
