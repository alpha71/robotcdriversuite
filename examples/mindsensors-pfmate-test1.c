#pragma config(Sensor, S1,     MSPFM,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-pfmate-test1.c $
 */

/**
 * mindsensors-pfmate.h provides an API for the Mindsensors PFMate.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 28 November 2009
 * version 0.2
 */

#include "mindsensors-pfmate.h"

void doTest(int channel) {
  displayTextLine(5, "Chan:  %d", channel);

  // -------- testing motor A -----------------------
  playSound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();
  displayTextLine(6, "Motor: A");
  displayTextLine(7, "Dir:   fwd");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor A forward from speed 1 to 7
    MSPFMcontrolMotorA(MSPFM, channel, MSPFM_FORWARD, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   brake");
  // Brake the motor
  MSPFMcontrolMotorA(MSPFM, channel, MSPFM_BRAKE, 0);
  sleep(500);

  displayTextLine(7, "Dir:   rev");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor A in reverse from speed 1 to 7
    MSPFMcontrolMotorA(MSPFM, channel, MSPFM_REVERSE, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   float");
  // Set motor A to float
  MSPFMcontrolMotorA(MSPFM, channel, MSPFM_FLOAT, 0);
  sleep(500);

  // -------- testing motor B -----------------------
  playSound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();
  displayTextLine(6, "Motor: B");
  displayTextLine(7, "Dir:   fwd");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor B forward from speed 1 to 7
    MSPFMcontrolMotorB(MSPFM, channel, MSPFM_FORWARD, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   brake");
  MSPFMcontrolMotorB(MSPFM, channel, MSPFM_BRAKE, 0);
  sleep(500);

  displayTextLine(7, "Dir:   rev");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor B in reverse from speed 1 to 7
    MSPFMcontrolMotorB(MSPFM, channel, MSPFM_REVERSE, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   float");
  MSPFMcontrolMotorB(MSPFM, channel, MSPFM_FLOAT, 0);
  sleep(500);

  // -------- testing motor A+B -----------------------
  playSound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();
  displayTextLine(6, "Motor: A+B");
  displayTextLine(7, "Dir:   fwd+rev");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor A forward and motor B in reverse from speed 1 to 7
    MSPFMcontrolMotorAB(MSPFM, channel, MSPFM_FORWARD, speed, MSPFM_REVERSE, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   brake");
  // brake both motors A and B
  MSPFMcontrolMotorAB(MSPFM, channel, MSPFM_BRAKE, 0, MSPFM_BRAKE, 0);
  sleep(500);

  displayTextLine(7, "Dir:   rev+fwd");
  for (int speed = 1; speed < 8; speed++) {
    // Run motor A in revese and motor B forward from speed 1 to 7
    MSPFMcontrolMotorAB(MSPFM, channel, MSPFM_REVERSE, speed, MSPFM_FORWARD, speed);
    sleep(500);
  }

  displayTextLine(7, "Dir:   float");
  // Put both motors in float
  MSPFMcontrolMotorAB(MSPFM, channel, MSPFM_FLOAT, 0, MSPFM_FLOAT, 0);
  sleep(500);
}

task main() {
  displayCenteredTextLine(0, "Mindsensors");
  displayCenteredBigTextLine(1, "PFMate");
  displayCenteredTextLine(3, "Test 1");
  sleep(2000);

  // Run through each channel for testing.
  for (int channel = 1; channel < 5; channel++) {
    doTest(channel);
  }
}

/*
 * $Id: mindsensors-pfmate-test1.c $
 */