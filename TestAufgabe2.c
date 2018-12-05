/*
 * TestAufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "TestAufgabe2.h"

void runTestSuffix(int no, TestCaseExtract test[]){
	Test t=OK;
	for(int i=0; i<no; i++){
		printf("Test %d:\n", i+1);
		t = testSuffix("::", test[i].input, test[i].expected);
		if(t==OK){
			printf("Test: OK");
		}else{
			printf("Test: FAIL");
		}
		printf("\n\n");
	}

}

Test testSuffix(char* pattern, char* input, char *expected){
	Test t=OK;
	int index=0;
	char *output = extract(input, pattern);
	while(output[index] != '\0'){
		if(output[index] == expected[index]){
			t=OK;
		}else{
			t=FAIL;
		}
		index++;
	}
	printf("Pattern: %s\nString: %s\n", pattern, input);
	printf("Output: %s\nExpected: %s\n", extract(input, pattern), expected);
	return t;
}

void runTestSuffix2(int no, TestCaseExtract test[]){

}

Test testSuffix2(char* pattern, char* input, char *expected){
	Test t=OK;
	char **output = &input;
	printf("Pattern: %s\nString: %s\n", pattern, input);
	extract2(input, output, pattern);
	printf("Output: %s, Expected: %s\n\n", *output , expected);
	return t;
}

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

