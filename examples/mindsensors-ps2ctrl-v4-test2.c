#pragma config(Sensor, S1,     PSPNXV4,        sensorI2CCustom)
#pragma config(Motor,  motorA,          ARMS,          tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          RIGHT,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          LEFT,          tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-ps2ctrl-v4-test2.c $
 */

/**
 * mindsensors-ps2ctrl-v4.h provides an API for the Mindsensors PS2 controller sensor
 * with referee signal receiver.  This program demonstrates how to use that API
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
 * 02 August 2012
 * version 0.1
 */

#include "mindsensors-ps2ctrl-v4.h"

task main ()
{
  ubyte counter = 0;
  ubyte oldCounter = 0;
  ubyte refSignal = 0;
  ubyte oldRefSignal = 0;
  ubyte txType = 0;
  long rawValue = 0;

  displayCenteredTextLine(0, "Mindsensors");
  displayCenteredBigTextLine(1, "PSP-Nx");
  displayCenteredTextLine(3, "Test 2");
  sleep(2000);

  playSound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();

  eraseDisplay();
  while (true)
  {
    // Get the current counter value, wraps at 255
    counter = PSPV4readRefSignalCount(PSPNXV4);

    if (oldCounter != counter)
    {
      // This is the command sent by the remote control, can be:
      // PSPV4_SIGNAL_FAST_REWIND
      // PSPV4_SIGNAL_FAST_FORWARD
      // PSPV4_SIGNAL_PLAY
      // PSPV4_SIGNAL_STOP
      refSignal =  PSPV4readRefSignal(PSPNXV4);

      // Get the transmitted type.  Not very useful in most cases unless
      // you need to know what type of transmitter sent the command
			txType = PSPV4readRefTXType(PSPNXV4);

			// Raw value will also "see" commands from the remote
			// that are not recognised as "play", "stop", "forward" or "rewind".
			// You could use this to control additional aspects of your robot!
			rawValue = PSPV4readRawRefTXValue(PSPNXV4);

      if (oldRefSignal != refSignal)
      {
	      playSound(soundShortBlip);
		    switch(refSignal)
		    {
		      case PSPV4_SIGNAL_FAST_REWIND:   displayCenteredBigTextLine(3,"REWIND"); break;
		      case PSPV4_SIGNAL_FAST_FORWARD:  displayCenteredBigTextLine(3,"FORWARD"); break;
		      case PSPV4_SIGNAL_PLAY:          displayCenteredBigTextLine(3,"PLAY"); break;
		      case PSPV4_SIGNAL_STOP:          displayCenteredBigTextLine(3,"STOP"); break;
		    }
		  }

		  // Always display the raw value, even if it's not one of the four
		  // referee signals.  Handy if you want to add more commands to your robot!
	    displayTextLine(6, "Type:  0x%02X", txType);
	    displayTextLine(7, "Raw:  0x%03X", rawValue);

	    // Update the counters and signals
	    oldCounter = counter;
	    oldRefSignal = refSignal;
	  }
    sleep(50);
  }
}


/*
 * $Id: mindsensors-ps2ctrl-v4-test2.c $
 */
