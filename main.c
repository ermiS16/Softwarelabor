/*
 * main.c
 *
 *  Created on: 27.10.2018
 *      Author: eric
 */

#include "main.h"


int main(){
	//Tests Aufgabe1
//	runSwitchTests();
//	runSerializeTests();
//	runDeserializeTests();
//	runSerializeDeserializeTests();
//	runDeserializeSerializeTests();
	//Tests Aufgabe2
	printf("-----------Start Test Suffix-------------\n\n");
	initializeTestCaseExtract();
	printf("-----------End Test Suffix-------------\n\n");
	printf("-----------Start Test Count Words-------------\n\n");
	initializeTestCasesCount();
	printf("-----------End Test Count Words-------------\n\n");
	//Tests Aufgabe3
	printf("-----------Start Test extract Words-------------\n\n");
	initializeTestCasesBreak();
	printf("-----------End Test extract Words-------------\n\n");
	return 0;
}

void initializeTestCaseExtract(void){
	TestCaseExtract testsExtractSuffix[TEST_NO_SUFFIX] = {
			       {"::", "", ""},
			       {"::", "Hallo", "Hallo"},
			       {"::", "::Hallo", "Hallo"},
			       {"::", "Hallo", "Hallo"},
			       {"::", ":::Hallo:::", ""},
			       {"::", "Hal::lo", "lo"},
			       {"::", "::Hal::lo", "lo"},
			       {"::", "Hal::lo:", "lo:"},
			       {"::", ":Hal:lo::", ""},
				   {"::", ":Hal::lo:", "lo:"},
				   {"l:", "Ha:ll:o::", "o::"},
				   {"l:", "Ha:l:l:o", "o"},
				   {"l:", "Hal::l:o:", "o:"},
				   {"l:", "Hal:l::o", ":o"},
			     };
		runTestSuffix(TEST_NO_SUFFIX, testsExtractSuffix);
}

void initializeTestCasesCount(void){

	TestCaseCount testsCountWords[9] = {
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
	runTestsCount(TEST_NO_COUNT, testsCountWords);
}

void initializeTestCasesBreak(void){
	char case1Input[] = "Dies ist ein Beispieltext";
	char *case1Expected[] = {"Dies", "ist", "ein", "Beispieltext"};
	char case2Input[] = "Dies ist ein Beispieltext";
	char *case2Expected[] = {"Dies", "ist", "ein", "Beispieltext"};
	char case3Input[] = "";
	char *case3Expected[] = {""};

	TestCaseBreakWord testCases[TEST_NO_BREAK] = {
			{case1Input, MAXWORDS1, EXPECTEDWORDS1, case1Expected},
			{case2Input, MAXWORDS2, EXPECTEDWORDS2, case2Expected},
			{case3Input, MAXWORDS3, EXPECTEDWORDS3, case3Expected}
	};
	runTestsBreakWord(TEST_NO_BREAK, testCases);
}






