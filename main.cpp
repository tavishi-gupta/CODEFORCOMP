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
bool MogoMechActive = true;
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
  //skills auton
  Drivetrain.setDriveVelocity(75, percent);
  wait(20, msec);

  Intake.spin(reverse, 60, pct); //Score alliance point
  Ramp.spin(forward, 60, pct);
  wait(1, sec);

  Drivetrain.driveFor(reverse, 380, mm); // drive to first tile
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  Intake.stop(brakeType::brake);
  Ramp.stop(brakeType::brake);

  Drivetrain.turnFor(left, 152, degrees); //turn right
  wait(20, msec);

  Drivetrain.setDriveVelocity(25, percent);
  wait(20, msec);

  Drivetrain.driveFor(forward, 650, mm); // drive to into mogo mech
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  MogoMechActive = false;
  MogoMech.set(MogoMechActive);
  wait(20, msec);

  Drivetrain.setDriveVelocity(75, percent);
  wait(20, msec);

  Drivetrain.turnFor(left, 310, degrees); //turn left
  wait(20, msec);

  Intake.spin(reverse, 60, pct); //To intake both rings
  Ramp.spin(forward, 60, pct);

  Drivetrain.setDriveVelocity(25, percent);
  wait(20, msec);

  Drivetrain.driveFor(reverse, 900, mm); // drive to into first ring
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);

  Drivetrain.driveFor(reverse, 525, mm); // drive to into first ring
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  Drivetrain.turnFor(right, 415, degrees); //turn right
  wait(20, msec);

  Intake.stop(brakeType::brake);
  Ramp.stop(brakeType::brake);
  wait(20, msec);

  Drivetrain.driveFor(forward, 475, mm); // drive back
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  MogoMechActive = true; //unclamp mobile goal
  MogoMech.set(MogoMechActive);
  wait(20, msec);

  Drivetrain.driveFor(reverse, 475, mm); // drive forward back into path. Recalculate this value
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  Drivetrain.turnFor(left, 95, degrees); //turn left to backwards position to clamp mogo mech
  wait(1, sec);

  Drivetrain.driveFor(reverse, 2500, mm); // drive backwards into the mogo mech
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);

  Drivetrain.setDriveVelocity(25, percent);
  wait(20, msec);

  Drivetrain.driveFor(forward, 650, mm); // drive to into mogo mech
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  MogoMechActive = false;
  MogoMech.set(MogoMechActive);
  wait(20, msec);

  Drivetrain.setDriveVelocity(75, percent);
  wait(20, msec);

  Drivetrain.turnFor(right, 310, degrees); //turn left
  wait(20, msec);

  Intake.spin(reverse, 60, pct); //To intake both rings
  Ramp.spin(forward, 60, pct);

  Drivetrain.setDriveVelocity(25, percent);
  wait(20, msec);

  Drivetrain.driveFor(reverse, 900, mm); // drive to into first ring
  Drivetrain.stop(brakeType::brake);
  wait(1, sec);

  Drivetrain.driveFor(reverse, 525, mm); // drive to into first ring
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  Drivetrain.turnFor(left, 415, degrees); //turn right
  wait(20, msec);

  Intake.stop(brakeType::brake);
  Ramp.stop(brakeType::brake);
  wait(20, msec);

  Drivetrain.driveFor(forward, 475, mm); // drive back
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

  MogoMechActive = true; //unclamp mobile goal
  MogoMech.set(MogoMechActive);
  wait(20, msec);

  Drivetrain.driveFor(reverse, 475, mm); // drive forward back into path. Recalculate this value
  Drivetrain.stop(brakeType::brake);
  wait(20, msec);

}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/
static bool intakeRampPressed = false;  // Track the button press state for Intake/Ramp control
static bool intakeReversePressed = false;  // Track the button press state for Intake/Ramp control

void usercontrol(void) {
  
  while (true) {  // Keep looping to continuously check the controller input
    // Check if ButtonA (MogoMech) was pressed and toggle the piston state
    if (Controller1.ButtonA.pressing()) {
      while(Controller1.ButtonA.pressing()){
        wait(10, msec);
      }
      MogoMechActive = !MogoMechActive;
      MogoMech.set(MogoMechActive);
    }

    // Check if ButtonB was pressed and toggle the motors for intake/ramp (forward/reverse)
    if (Controller1.ButtonX.pressing()) {
        // Mark the button press state
      while (Controller1.ButtonX.pressing()) {
        wait(10, msec);
      }
      intakeReversePressed = !intakeReversePressed;

      if (intakeReversePressed) {
        Ramp.spin(reverse, 70, pct);
        Intake.spin(forward, 70, pct);
      } else {
        Intake.stop(brakeType::brake);
        Ramp.stop(brakeType::brake);
      }
    }

    // Check if ButtonY was pressed and toggle the motors for intake/ramp (reverse/forward)
    if (Controller1.ButtonY.pressing() && !intakeRampPressed) {
      while (Controller1.ButtonY.pressing()) {
        wait(10, msec);
      }
      intakeReversePressed = !intakeReversePressed;

      if (intakeReversePressed) {
        Ramp.spin(forward, 50, pct);
        Intake.spin(reverse, 50, pct);
      } else {
        Intake.stop(brakeType::brake);
        Ramp.stop(brakeType::brake);
      }
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
