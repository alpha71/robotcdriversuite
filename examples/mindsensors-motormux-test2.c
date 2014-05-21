#pragma config(Sensor, S1,     MSMMUX,              sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-motormux-test2.c $
 */

/**
 * mindsensors-motormux.h provides an API for the Mindsensors Motor MUX. This program
 * demonstrates how to use that API to control the motors attached to the MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 30 May 2011
 * version 0.1
 */

#include "mindsensors-motormux.h"
#include "mindsensors-irdist.h"

// configure MSDIST to also be connected to S1 as well, through the MMUX
#define MSDIST S1

task main () {
  long encA  = 0;
  long encB  = 0;

  long distance = 0;
  long mindist = 0;
  long maxdist = 0;

  int motorSpeed = 0;

  eraseDisplay();
  MSMMUXinit();

  MSMotorStop(mmotor_S1_1);
  MSMotorStop(mmotor_S1_2);

  sleep(500);

  // Reset the encoders.  This can be done individually or all at once.
  // You should do this at the start of your program.
  MSMMotorEncoderResetAll(MSMMUX);

  // Read the minimum distance the sensor can "see"
  mindist = MSDISTreadMinDist(MSDIST);

  // Read the maximum distance the sensor can "see"
  maxdist = MSDISTreadMaxDist(MSDIST);

  while (true) {
    distance = MSDISTreadDist(MSDIST);

    // Retrieve the motor-MUX's encoder counts
    encA = MSMMotorEncoder(mmotor_S1_1);
    encB = MSMMotorEncoder(mmotor_S1_2);

    // calculate the motor speed
    motorSpeed = ((distance - mindist) * 100) / (maxdist - mindist);

	  // Tell the motors to start moving.
	  MSMMotor(mmotor_S1_1, motorSpeed);
	  MSMMotor(mmotor_S1_2, motorSpeed);

		// Display the info.
		displayTextLine(4, "D: %5d", distance);
		displayTextLine(5, "A: %5d (%3d)", encA, motorSpeed);
		displayTextLine(6, "B: %5d (%3d)", encB, motorSpeed);
    sleep(20);
  }
}

/*
 * $Id: mindsensors-motormux-test2.c $
 */
