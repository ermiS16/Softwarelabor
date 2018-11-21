/*
 * aufgabe2.h
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */

#ifndef AUFGABE2_H_
#define AUFGABE2_H_


#include "libs.h"

char* extract(char *input, char *pattern);
void extract2(char *input, char **output, char *pattern);


char* leerzeichen(char* input);
char* zeichen(char* input);
int count(char* input);
#endif /* AUFGABE2_H_ */
