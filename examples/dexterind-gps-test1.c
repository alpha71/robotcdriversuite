#pragma config(Sensor, S1,     DGPS,                sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: dexterind-gps-test1.c $
 */

/**
 * dexterind-gps.h provides an API for the Dexter Industries GPS Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h from includes
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.2
 */

#include "dexterind-gps.h"

task main () {

  long longitude = 0;
  long latitude = 0;
  long utc = 0;
  bool linkstatus = false;

  displayCenteredTextLine(0, "Dexter Ind.");
  displayCenteredBigTextLine(1, "GPS");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);
  eraseDisplay();

  while (true) {
    // Read the sensor's data
    utc = DGPSreadUTC(DGPS);
    longitude = DGPSreadLongitude(DGPS);
    latitude = DGPSreadLatitude(DGPS);
    linkstatus = DGPSreadStatus(DGPS);

    displayCenteredTextLine(0, "DGPS Test 1");
    drawLine(0, 52, 99, 52);
    displayTextLine(2, "UTC: %d", utc);
    displayTextLine(3, "Lon: %d", longitude);
    displayTextLine(4, "Lat: %d", latitude);
    if (linkstatus)
      displayTextLine(7, "Link Stat: [UP]");
    else
      displayTextLine(7, "Link Stat: [DOWN]");
    drawLine(0, 20, 99, 20);
    sleep(500);
  }
}

/*
 * $Id: dexterind-gps-test1.c $
 */
