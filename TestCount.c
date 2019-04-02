/*
 * TestCount.c
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#include "count.h"
#include "TestCount.h"


Test testCount(char* input, int expected) {
  Test t;
  int amountWords = 0;

  amountWords = count(input);
  printf("String: %s, ", input);
  printf("Anzahl Worter: %d, ", amountWords);
  printf("Erwarte Anzahl: %d\n", expected);
  if(expected == amountWords) {
    t = OK;
  }
  else {
    t = FAIL;
  }
  return t;
}

void runTestsCount(int no, TestCaseCount test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d: , ", i+1);
    t = testCount(test[i].input, test[i].expected);
    if(OK == t)
      printf("Test OK \n\n");
    if(FAIL == t)
      printf("Test FAIL \n");
  }
}
