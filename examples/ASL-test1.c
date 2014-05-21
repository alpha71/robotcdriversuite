#pragma config(Sensor, S3,     ASL,            sensorI2CCustom)
#pragma config(Sensor, S4,     TOUCH,          sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: ASL-test1.c $
 */

/**
 * ASL-driver.h provides an API for the <SENSOR>.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to <MANUFACTURER> for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 04 February 2012
 * version 0.1
 */

#include "ASL-driver.h"

task main () {
  int dynval = 0;
  int statval = 0;
  int threshval = 0;
  int rval, lval, bval;
  long level = 0;
  ubyte threshold = 0;

  displayCenteredTextLine(0, "Lizard");
  displayCenteredTextLine(1, "Monkey Hear");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);

  playSound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();

  level = ASLcalibrateLevel(ASL);
  threshold = (level * 120) / 100;


  for (int i = 0; i < 1000; i++) {
    eraseDisplay();
    displayTextLine(0,"HTAC Test 1");

    // Read all of the axes at once
    statval = ASLreadStaticAngle(ASL, false);
    dynval = ASLreadDynamicAngle(ASL, false);
    threshval = ASLreadThresholdAngle(ASL, threshold, false);
    ASLreadMICS(ASL, rval, lval, bval);

    displayTextLine(2, "stat: %d", statval);
    displayTextLine(3, "dyn:  %d", dynval);
    displayTextLine(4, "rval:  %d", rval);
    displayTextLine(5, "lval:  %d", lval);
    displayTextLine(6, "bval:  %d", bval);
    writeDebugStream("%d,%d,", statval, dynval);
    writeDebugStream("%d,", threshval);
    writeDebugStream("%d,%d,", rval, lval);
    if (SensorValue[TOUCH])
      writeDebugStream("true,");
    else
      writeDebugStream("false,");
    writeDebugStreamLine("%d", bval);
    sleep(10);
  }
}

/*
 * $Id: ASL-test1.c $
 */