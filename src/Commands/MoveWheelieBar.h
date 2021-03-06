// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef MOVEWHEELIEBAR_H
#define MOVEWHEELIEBAR_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 * This class encapsulates the code to move the wheelie bar.
 */
class MoveWheelieBar: public Command {
public:
	/*
	 * Initializes a new instance of the MoveWheelieBar class. This constructor will initialize a new
	 * move wheelie bar command. This is the default command for the WheelieBar subsystem.
	 *
	 * @param previousState: This is the initial condition of the wheelie bar (will reset to true always)
	 * @param pushedButton: This injects the initial condition of pushing the button. In autonomous, this will
	 * 	actually change the position to move the wheelie bar to.
	 * @param isAuto: Discerns whether or not this is an sutonomous call.
	 */
	MoveWheelieBar(bool previousState, bool pushedButton, bool isAuto=false);

	/*
		 * This method is called to run once when this command runs.
		 */
		virtual void Initialize();

		/*
		 * This is the method that will actually take in inputs from the joysticks and move the finger.
		 */
		virtual void Execute();

		/*
		 * This method determines if the wheelie bar command control has actually completed.
		 * In Teleop, we should never complete this command.
		 */
		virtual bool IsFinished();

		/*
		 * This is the method called once when it is declared "finished". We do nothing here.
		 */
		virtual void End();

		/*
		 * This method gets called when another instance of the command is called and we need to let it go.
		 * We shouldn't do anything special here...
		 */
		virtual void Interrupted();

private:
	/*
	 * This is the internal state to see what state the wheelie bar is in.
	 */
    bool previousState;

    /*
     * This is an internal state that determines if the button was pushed the last time around.
     */
    bool pushedButton;

    /*
     * This variable is a flag that determines whether or not this is running autonomously.
     */
    bool isAuto;
};

#endif
