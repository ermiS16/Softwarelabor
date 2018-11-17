/*
 * typedefs.h
 *
 *  Created on: 27.10.2018
 *      Author: eric
 */

#ifndef ENUMS_H_
#define ENUMS_H_

typedef enum{
	Stop = 0,
	Start = 1,
	Finish = 5,
	Fail = 255
}Status;

typedef enum{
	One = 1,
	Fifteen = 15,
	Last = 255
}Numbers;

enum TestEnum{
	OK = 1,
	FAIL = 0
};
typedef enum TestEnum Test;



#endif /* ENUMS_H_ */
