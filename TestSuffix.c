/*
 * TestSuffix.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "TestSuffix.h"

void runTestSuffix(int no, TestCaseExtract test[]){
	Test t=OK;
	for(int i=0; i<no; i++){
		printf("Test %d:\n", i+1);
		t = testSuffix(test[i].pattern, test[i].input, test[i].expected);
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
	while(output[index] != '\0' && expected[index != '\0']){
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
	Test t=OK;
	for(int i=0; i<no; i++){
		printf("Test %d:\n", i+1);
		t = testSuffix2(test[i].pattern, test[i].input, test[i].expected);
		if(t==OK){
			printf("Test: OK");
		}else{
			printf("Test: FAIL");
		}
		printf("\n\n");
	}
}

Test testSuffix2(char* pattern, char* input, char *expected){
	Test t=OK;
	char **output = &input;

	printf("Pattern: %s\nString: %s\n", pattern, input);
	extract2(input, output, pattern);
	printf("Output: %s, Expected: %s\n", *output , expected);
	return t;
}

