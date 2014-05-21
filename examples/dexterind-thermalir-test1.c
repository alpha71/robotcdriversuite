#pragma config(Sensor, S1,     TIR,            sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * dexterind-thermalir.h provides an API for the Dexter Industries Thermal Infrared Sensor.  This program
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
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 30 march 2013
 * version 0.1
 */


#include "dexterind-thermalir.h"

task main () {

  // declare and initialise the sensor
  tTIR tir;
  initSensor(&tir, S1);

  displayCenteredTextLine(0, "Dexter Industries");
  displayCenteredTextLine(1, "Thermal Infrared");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);

	eraseDisplay();

  // set emissivity for light skin
  setEmissivity(&tir, TIR_EM_SKIN_LIGHT);

  sleep(200);

  displayCenteredTextLine(0, "Dexter Industries");
  displayCenteredTextLine(1, "Thermal Infrared");
  while (true) {
    // Read the currently detected ambient and object temp from the sensor
    sensorReadAll(&tir);

    displayTextLine(3, "A: %3.2f", tir.ambientTemp);
    displayTextLine(4, "O: %3.2f", tir.objectTemp);
    sleep(100);
  }
}
