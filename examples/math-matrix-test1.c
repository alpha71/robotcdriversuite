//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: math-matrix-test1.c $
 */

/**
 * matrix-float .h provides an API for the some simple Matrix operations.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Charlie Matlack for writing the Arduino version of this.  I merely ported it to
 *   ROBOTC and tweaked a few things.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.0 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 03 March 2013
 * version 0.1
 */

#include "math-matrix.h"

task main ()
{
  float one[2][2] = {{2.7, 2.1}, {1.1, 1.6}};
  float two[2][2] = {{12.1, 11.9}, {21, 82.1}};
  float three[2][2];

  long four[3][3] = {{1, 3, 3},
                     {1, 4, 3},
                     {1, 3, 4}};

  long five[3][3] = {{2, 1, 7},
                     {3, 4, 1},
                     {4, 2, 1}};

  long six[3][3];

  matrixPrintF(one, 2, 2, "one");
  matrixMultF(one, two, 2, 2, 2, three);
  matrixPrintF(three, 2, 2, "three");
  matrixCopyF(one, 2, 2, two);
  matrixPrintF(one, 2, 2, "one");
  matrixPrintF(two, 2, 2, "two");

  matrixAddL(four, five, 3, 3, six);
  matrixPrintL(six, 3, 3, "six");

}
