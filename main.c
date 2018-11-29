/*
 * main.c
 *
 *  Created on: 27.10.2018
 *      Author: eric
 */

//#include "libs.h"
#include "main.h"
//#include "TestCase.h"

#define TEST_NO_COUNT 3


int main(){
	//Tests Aufgabe1
//	runSwitchTests();
//	runSerializeTests();
//	runDeserializeTests();
//	runSerializeDeserializeTests();
//	runDeserializeSerializeTests();
	//Tests Aufgabe2
//	runTests();
//	runTests2();
//	const int testNo = 9;

//	runTests3(TEST_NO_COUNT,initializeTestCasesCount());

	//Tests Aufgabe3
	  runTests4(TEST_NO_COUNT, initializeTestCasesBreak());
	return 0;
}

TestCaseCount *initializeTestCasesCount(void){

	TestCaseCount static testsCountWords[9] = {
		       {"", 0},
		       {"Hallo", 1},
		       {"  Hallo", 1},
		       {"Hallo", 1},
		       {"  Hallo  ", 1},

		       {"Hal lo", 2},
		       {" Hal lo", 2},
		       {"Hal lo ", 2},
		       {" Hal lo  ", 2}
		     };
	return testsCountWords;
}

TestCaseBreakWord* initializeTestCasesBreak(void){
	char static case1Input[] = "Dies ist ein Beispieltext";
	char static *case1Expected[] = {"Dies", "ist", "ein", "Beispieltext"};
	int maxwords1 = 5;
	int expectedWords1 = 4;
	char static case2Input[] = "Dies ist ein Beispieltext";
	char static *case2Expected[] = {"Dies", "ist", "ein", "Beispieltext"};
	int maxwords2 = 3;
	int expectedWords2 = 3;
	char static case3Input[] = "";
	char static *case3Expected[] = {""};
	int maxwords3 = 5;
	int expectedWords3 = 0;

	TestCaseBreakWord static testCases[TEST_NO_COUNT] = {
			{case1Input, 4, 5, case1Expected},
			{case2Input, 3, 3, case2Expected},
			{case3Input, 0, 5, case3Expected}
	};
	return testCases;
}






