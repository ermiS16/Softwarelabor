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


#endif /* TESTCASE_H_ */
