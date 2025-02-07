/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of competition
competition Competition;

// Define global instances of motors and other devices
bool MogoMechActive = false;
bool motorsRunning = false;  // Tracks the motor position toggle

// Motor for the rotational sensor (assumed to be a motor with a rotational sensor)
// Assuming a rotation sensor is attached to the motor

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {  // Initializing Robot Configuration. DO NOT REMOVE!
  // Reset the motor to 0 degrees at the start of the match
  //RotatingMotor.resetRotation();
  //RotatingMotor.setPosition(0, degrees);
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/



void autonomous(void) {
  // Autonomous code here (not modified for now)
  //left side
  /*Drivetrain.setDriveVelocity(75, percent);  // Set the drivetrain speed
  Drivetrain.driveFor(forward, 30, inches);   // Drive forward for 24 inches
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);
  MogoMech.set(true);
  wait(1, sec);
  Drivetrain.driveFor(forward, 6, inches);
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);
  Intake.spin(reverse, 100, pct);
  Ramp.spin(forward, 80, pct);
  wait(1, sec);
  Drivetrain.turnFor(right, 90, degrees);
  wait(1, sec);
  Drivetrain.driveFor(forward, 22, inches);
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);
  Intake.spin(reverse, 100, pct);
  Ramp.spin(forward, 80, pct);
  wait(1, sec);
  Drivetrain.driveFor(forward, 8, inches);
  Drivetrain.stop(brakeType::brake);*/

  //right side
  //Drivetrain.setDriveVelocity(75, percent);  // Set the drivetrain speed
  //Drivetrain.driveFor(forward, 30, inches);   // Drive forward for 24 inches
  //Drivetrain.stop(brakeType::brake);
  //wait(1, sec);
  //MogoMech.set(true);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 6, inches);
  //Drivetrain.stop(brakeType::brake);
  //Intake.spin(reverse, 100, pct);
  //Ramp.spin(forward, 80, pct);
  //wait(1, sec);
  //wait(1, sec);
  //Drivetrain.turnFor(left, 90, degrees);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 22, inches);
  //Drivetrain.stop(brakeType::brake);
  //wait(1, sec);
  //Intake.spin(reverse, 100, pct);
  //Ramp.spin(forward, 80, pct);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 8, inches);
  //Drivetrain.stop(brakeType::brake);
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  static bool mogoPressed = false;  // Track the button press state for MogoMech
  static bool intakeRampPressed = false;  // Track the button press state for Intake/Ramp control
  
  while (true) {  // Keep looping to continuously check the controller input
    // Check if ButtonA (MogoMech) was pressed and toggle the piston state
    if (Controller1.ButtonA.pressing() && !mogoPressed) {
      mogoPressed = true;  // Mark the button press state
      MogoMechActive = !MogoMechActive;  // Toggle the MogoMech state
      MogoMech.set(MogoMechActive);  // Update MogoMech state
    } else if (!Controller1.ButtonA.pressing()) {
      mogoPressed = false;  // Reset the button state when it's released
    }

    // Check if ButtonB was pressed and toggle the motors for intake/ramp (forward/reverse)
    if (Controller1.ButtonB.pressing() && !intakeRampPressed) {
      intakeRampPressed = true;  // Mark the button press state
      motorsRunning = !motorsRunning;  // Toggle the motor state
      if (motorsRunning) {
        Intake.spin(forward);  // Spin intake forward
        Ramp.spin(reverse);  // Spin ramp in reverse
      } else {
        Intake.stop();  // Stop intake
        Ramp.stop();  // Stop ramp
      }
    } else if (!Controller1.ButtonB.pressing()) {
      intakeRampPressed = false;  // Reset the button state when it's released
    }

    // Check if ButtonY was pressed and toggle the motors for intake/ramp (reverse/forward)
    if (Controller1.ButtonY.pressing() && !intakeRampPressed) {
      intakeRampPressed = true;  // Mark the button press state
      motorsRunning = !motorsRunning;  // Toggle the motor state
      if (motorsRunning) {
        Intake.spin(reverse);  // Spin intake reverse
        Ramp.spin(forward);  // Spin ramp forward
      } else {
        Intake.stop();  // Stop intake
        Ramp.stop();  // Stop ramp
      }
    } else if (!Controller1.ButtonY.pressing()) {
      intakeRampPressed = false;  // Reset the button state when it's released
    }
    
    wait(10, msec);  // Short delay for debouncing and task looping
  }
}


int main() {
  vexcodeInit(); // Initialize devices
  // Set up callbacks for autonomous and driver control periods
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function
  pre_auton();

  // Prevent main from exiting with an infinite loop
  while (true) {
    wait(100, msec);
  }
}
