/********************************************************************************************
File: PseudoParallelProcessing.ino

Description:
  
  It is some times necessary to run a specific code ever so often, generally the easiest way to do this is to 
  just use the function delay() to wait the required interval. The problem with this strategy is that the processor
  actually gets stuck in a loop while waiting for the interval to end.
  This file tests a library that helps to easily implement routines that can be processed in parallel, well not really,
  rather the idle time of each routine can be used to process other routines! 
  
Sources used:

  The example published by Robin2 (http://forum.arduino.cc/index.php?topic=223286.0) more or less demonstrates what is
  implemented in the libraries

Notes: 

Author: Fernando Figueiredo
License: GNU GPL
Creation: 2017-09-04
Last modification: 2017-09-04
********************************************************************************************/

#include "src/PseudoParallelProcessing/PseudoParallelProcessing.h"

#define LED 33 //LED Pin for Maple Mini
//#define LED 13 //LED Pin for Arduino

void CyclicProcess();
void BlinkLED();
void IncreaseCounter();


PseudoParallelProcessing multiTasker1(CyclicProcess);
PseudoParallelProcessing multiTasker2(BlinkLED);
PseudoParallelProcessing multiTasker3(IncreaseCounter);
int iNow = 0;
int iCounter = 0;

void setup()
{
  Serial.begin();
  pinMode(LED, OUTPUT);
}

void loop() {
  iNow = (int)millis();
  multiTasker1.RunIt(500, iNow);
  multiTasker2.RunIt(120, iNow);
  multiTasker3.RunIt(100, iNow);      
}

void CyclicProcess()
{
   Serial.println("Counter = " + String(iCounter));  
}

void BlinkLED()
{
   digitalWrite(LED,!digitalRead(LED));
}

void IncreaseCounter()
{
   iCounter++;
}
