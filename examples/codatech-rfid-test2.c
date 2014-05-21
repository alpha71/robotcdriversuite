#pragma config(Sensor, S1,     CTRFID,              sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: codatech-rfid-test2.c $
 */

/**
 * codatech-rfid.h provides an API for the Codatex RFID sensor.  This program
 * demonstrates how to use that API to use the sensor in continuous mode.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h include
 *
 * Credits:
 * - Big thanks to Sylvain Cacheux for writing the initial drivers.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 20 february 2011
 * version 0.2
 */

#include "codatech-rfid.h"

string transponderID;

task main()
{
  nNxtButtonTask  = -2;
  displayCenteredTextLine(0, "Codatex");
  displayCenteredBigTextLine(1, "RFID");
  displayCenteredTextLine(3, "Test 2");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);

  eraseDisplay();
  displayCenteredTextLine(3, "Start single");
  displayCenteredTextLine(4, "reading loop");
  sleep(2000);
  eraseDisplay();

  // Set up the sensor for continuous readings.
  CTRFIDsetContinuous(CTRFID);

  // loop for transponder readings with continuous read function
  while(nNxtButtonPressed == kNoButton) {
    // read the transponder
    if (!CTRFIDreadTransponder(CTRFID, transponderID)) {
      eraseDisplay();
      displayTextLine(3, "Error reading");
      displayTextLine(4, "from sensor!");
      sleep(5000);
      stopAllTasks();
    }
    displayCenteredTextLine(3, "Transponder ID:");
    displayCenteredTextLine(4, "%s", transponderID);

    // Be sure to add about 200ms after each read
    // or you end up getting 0000000000 as a transponder address
    sleep(200);
  }
}

/*
 * $Id: codatech-rfid-test2.c $
 */