/********************************************************************************************
File: PseudoParallelProcessing.h

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

#ifndef PseudoParallelProcessing_h
#define PseudoParallelProcessing_h

	
class PseudoParallelProcessing
{	
	// Define a callback type: a pointer to a function taking no
	// arguments and returning void.
	typedef void (*callback_t)();

  public:
		PseudoParallelProcessing(callback_t);
	  void setCallback(void (*Callback));
    void RunIt(int, int);
	private:
		int iLastExecutionInstant;
	  callback_t callback;

};

#endif