#pragma config(Sensor, S1,     MSLSA,          sensorI2CCustomFastSkipStates9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-ligthsensorarray-test3.c $
 */

/**
 * mindsensors-lightsensorarray.h provides an API for the Mindsensors LightSensorArray Sensor.  This program
 * demonstrates how to use that API.
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
 * 30 September 2012
 * version 0.1
 */

#include "mindsensors-lightsensorarray.h"

const string frequencyNames[] = {"US", "UNI", "EU", };

// Set the desired frequency compensation mode.  This has to do with the frequency of the
// AC current.  It causes flickering of the lights at the same frequency and can
// interfere with the sensor readings. This allows you to compensate for it.
void setFrequency(int choice)
{
  playSound(soundBlip);
  switch(choice)
  {
    case 0: MSLSAsetUS(MSLSA);  break;
    case 1: MSLSAsetUni(MSLSA); break;
    case 2: MSLSAsetEU(MSLSA);  break;
  }
}

task main {
  int choice = 1;

  while (true) {
    switch(nNxtButtonPressed)
    {
      case kEnterButton: setFrequency(choice); break;
      case kLeftButton:  choice = (choice == 0) ? 0 : (choice - 1); break;
      case kRightButton: choice = (choice == 2) ? 2 : (choice + 1); break;
    }

    displayCenteredTextLine(0, "LightSensorArray");
    displayCenteredTextLine(1, "Freq. config");
    displayCenteredBigTextLine(3, frequencyNames[choice]);
    displayCenteredTextLine(6, "[enter] to set");
    displayTextLine(7, "<  switch freq  >");

    // Debounce
    while (nNxtButtonPressed != kNoButton) EndTimeSlice();
  }
}

/*
 * $Id: mindsensors-ligthsensorarray-test3.c $
 */
