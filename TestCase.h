/*
 * TestCases.h
 *
 *  Created on: 28.11.2018
 *      Author: eric
 */

#ifndef TESTCASE_H_
#define TESTCASE_H_


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

TestCaseBreakWord testsBreakIntoWords[2] = {
		{"Dies ist ein Beispieltext", 5, "DieB"},
		{"Ha ll o", 3, "Hlo"}
};

#endif /* TESTCASE_H_ */
