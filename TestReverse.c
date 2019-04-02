/*
 * TestReverse.c
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#include "TestReverse.h"


void runTestsReverse(int no, TestCaseReverse test[]){
	Test t=OK;
	for(int i=0; i<no; i++){
		printf("Test %d:\n", i+1);
		t = testReverse(test[i].input, test[i].expected);
		if(t==OK){
			printf("Test: OK");
		}else{
			printf("Test: FAIL");
		}
		printf("\n\n");
	}

}

Test testReverse(char *input, char *expected){
	Test t=FAIL;
	int index=0;
	char *output = reverse(input);

	//Special Case: Empty String
	if(*output == '\0' && *output == *expected){
		t=OK;
	}
	while(output[index] != '\0' && expected[index != '\0']){
		if(output[index] == expected[index]){
			t=OK;
		}else{
			t=FAIL;
		}
		index++;
	}
	printf("Input: %s\nOutput: %s\nExpected: %s\n", input, reverse(input), expected);
	return t;
}


