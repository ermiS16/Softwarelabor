/*
 * TestAufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "TestAufgabe2.h"

void runTests(){
	char pattern[] = "::";
	char string[] = {"Du::Bist::Ein::Idiot"};
	char expected[] = {"Idiot"};
	testSuffix(pattern, string, expected);
}

Test testSuffix(char* pattern, char* input, char *expected){
	Test t=OK;
	printf("Pattern: %s\nString: %s\n", pattern, input);
	printf("Output: %s, Expected: %s\n", extract(input, pattern), expected);
	return t;
}

void runTests2(){
	char pattern[] = "::";
	char string[] = {"Du::Bist::Ein::Idiot"};
	char expected[] = {"Idiot"};
	testSuffix2(pattern, string, expected);
}

Test testSuffix2(char* pattern, char* input, char *expected){
	Test t=OK;
	char **output = &input;
	printf("Pattern: %s\nString: %s\n", pattern, input);
	extract2(input, output, pattern);
	printf("Output: %s, Expected: %s\n", *output , expected);
	return t;
}







Test testCount(char* input, int expected) {
  Test t;

  if(expected == count(input)) {
    t = OK;
  }
  else {
    t = FAIL;
  }
  return t;
}

void runTests3(int no, TestCase test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d: ", i);
    t = testCount(test[i].input, test[i].expected);
    if(OK == t)
      printf("OK \n");
    if(FAIL == t)
      printf("FAIL \n");
  }
}

