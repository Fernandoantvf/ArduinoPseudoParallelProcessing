# ArduinoPseudoParallelProcessing
A simple way to setup parallel processing of routines in any arduino

Description:

  It is some times necessary to run a specific code ever so often, generally the easiest way to do this is to 
  just use the function delay() to wait the required interval. The problem with this strategy is that the processor
  actually gets stuck in a loop while waiting for the interval to end.
  This file tests a library that helps to easily implement routines that can be processed in parallel, well not really,
  rather the idle time of each routine can be used to process other routines!
  
  I other words, this library can be used to setup routines running on diferent threads
