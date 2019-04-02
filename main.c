/*
 * main.c
 *
 *  Created on: 27.10.2018
 *      Author: eric
 */

#include "main.h"


int main(){

	//Aufgabe 1
	printf("-----------Start Test LowHigh-------------\n\n");
	initializeTestCaseLowHigh();
	printf("-----------End Test LowHigh-------------\n\n");
	printf("-----------Start Test Serialize-------------\n\n");
	initializeTestCaseSerialize();
	printf("-----------End Test Serialize-------------\n\n");
	printf("-----------Start Test Deserialize-------------\n\n");
	initializeTestCaseDeserialize();
	printf("-----------End Test Deserialize-------------\n\n");
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

	printf("-----------Start Test Reverse-------------\n\n");
	initializeTestCasesReverse();
	printf("-----------End Test Reverse-------------\n\n");


	return 0;
}

void initializeTestCaseLowHigh(void){

	TestCaseLowHigh testLowHigh[TEST_NO_LOWHIGH] = {
			{0x0001,0x0100},
			{0x1000,0x0010},
			{0x1001,0x0110},
			{0x0110,0x1001},
			{0x1100,0x0011},
			{0x0011,0x1100},
			{0x1110,0x1011},
			{0x0111,0x1101},
			{0x0101,0x0101},
			{0x1010,0x1010},
			{0xABCD,0xCDAB}
	};
	runTestLowHigh(TEST_NO_LOWHIGH, testLowHigh);
}
void initializeTestCaseSerialize(void){

	TestCaseSerialize test[] = {
			{Stop,One,0x0001},
			{Stop,Fifteen,0x000F},
			{Stop,Last,0x00FF},
			{Start,One,0x0101},
			{Start,Fifteen,0x010F},
			{Start,Last,0x01FF},
			{Finish,One,0x0501},
			{Finish,Fifteen,0x050F},
			{Finish,Last,0x05FF},
			{Fail,One,0xFF01},
			{Fail,Fifteen,0xFF0F},
			{Fail,Last,0xFFFF}
	};
	runTestSerialize(TEST_NO_SERIALIZE, test);
}
void initializeTestCaseDeserialize(void){
	TestCaseDeserialize test[] = {
			{0x0001,Stop,One},
			{0x000F,Stop,Fifteen},
			{0x00FF,Stop,Last},
			{0x0101,Start,One},
			{0x010F,Start,Fifteen},
			{0x01FF,Start,Last},
			{0x0501,Finish,One},
			{0x050F,Finish,Fifteen},
			{0x05FF,Finish,Last},
			{0xFF01,Fail,One},
			{0xFF0F,Fail,Fifteen},
			{0xFFFF,Fail,Last}
	};
		runTestDeserialize(TEST_NO_DESERIALIZE, test);
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

void initializeTestCasesReverse(void){

	TestCaseReverse testCases[TEST_NO_REVERSE] = {
			{"12345", "54321"},
			{"Hallo", "ollaH"},
			{"Hallo Welt", "tlew ollaH"},
			{"Hallo-Welt", "tlew-ollaH"},
			{"", ""},
			{"H","H"}
	};
	runTestsReverse(TEST_NO_REVERSE, testCases);
}





