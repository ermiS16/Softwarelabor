/*
 * aufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "aufgabe2.h"

char* extract(char *input, char *pattern){
	char *position = input;
	int matching = 0;
	int index=0;
	printf("Pattern length: %d\n", strlen(pattern));

	//Pattern Matching
	while(*input != '\0'){
		if(*input == *pattern){
			index = 0;
			while(index<strlen(pattern)){
				if(*input == pattern[index]){
					matching=1;
					input++;
				}else{
					matching=0;
				}
				index++;
			}
		}else{
			input++;
		}

		if(matching){
			position = input;
			matching = 0;
		}
	}



	return position;
}
