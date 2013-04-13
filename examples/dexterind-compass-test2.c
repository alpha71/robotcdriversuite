#pragma config(Sensor, S1,     DIMC,           sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: dexterind-compass-test2.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * dexterind-compass.h provides an API for the Dexter Industries dCompass Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER.

 * Xander Soldaat (xander_at_botbench.com)
 * 14 March 2012
 * version 0.1
 */

#include "dexterind-compass.h"

task main(){

  int x_val, y_val, z_val;      // Compass axes values
  float heading;

  nxtDisplayCenteredTextLine(0, "Dexter Ind.");
  nxtDisplayCenteredBigTextLine(1, "dCompass");
  nxtDisplayCenteredTextLine(3, "Test 2");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);
  eraseDisplay();


  // Fire up the compass and initialize it. Only needs to be done once.
  if (!DIMCinit(DIMC))
    PlaySound(soundException);

  // This program uses an omniwheel platform to rotate the robot about
  // its axis a few times but you can use another robot to do this.
  // Just make sure the robot rotates around 2-3 times about is axis
  DIMCstartCal(DIMC);

  nxtDisplayCenteredTextLine(1, "Calibrating...");
  nxtDisplayCenteredTextLine(2, "Turn the sensor");
  nxtDisplayCenteredTextLine(3, "slowly");

  time1[T1] = 0;
  while(time1[T1] < 15000)
  {
    DIMCreadAxes(DIMC, x_val, y_val, z_val);
    if (time1[T1] % 1000 < 10)
      nxtDisplayCenteredBigTextLine(5, "%d", 15 - (time1[T1]/1000));

  }

  // Stop the calibration and store the data
  DIMCstopCal(DIMC);

  eraseDisplay();
  wait1Msec(100);
  while (true){

		// Read the Compass
    DIMCreadAxes(DIMC, x_val, y_val, z_val);
    heading = DIMCreadHeading(DIMC);

    nxtDisplayCenteredBigTextLine(1, "Heading");
    nxtDisplayCenteredBigTextLine(3, "%3.2f", heading);
		nxtDisplayTextLine(5, "%d", x_val);
		nxtDisplayTextLine(6, "%d", y_val);
		nxtDisplayTextLine(7, "%d", z_val);
		wait1Msec(50);
  }
}

/*
 * $Id: dexterind-compass-test2.c 133 2013-03-10 15:15:38Z xander $
 */
