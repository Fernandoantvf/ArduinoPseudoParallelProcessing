/********************************************************************************************
File: PseudoParallelProcessing.cpp

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

#include "PseudoParallelProcessing.h"

/**
  * @brief  Initializes an instance of PseudoParallelProcessing
  * @param  none
  * @retval None
  */
PseudoParallelProcessing::PseudoParallelProcessing(callback_t _callback)
{
	callback = _callback;
}

/**
  * @brief  Checks if required interval has passed, if so runs routine
  * @param  iScanInterval - delay between executions(millis);  lNow - current moment (millis)
  * @retval None
  */
void PseudoParallelProcessing::RunIt(int iScanInterval, int iNow)
{
	//Check if elapsed time is at least equal to the scan interval
	//If so callback function, else just return and free the processor
	if ((iNow - iLastExecutionInstant) >= iScanInterval )
	{
		iLastExecutionInstant = iNow;
		callback();
	}
}

