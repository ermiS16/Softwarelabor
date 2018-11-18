/*
 * aufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "aufgabe2.h"

char* extract(char *input, char *pattern){
	char *position = input;
	char *temp;
	int matching = 0;
	printf("Pattern length: %d\n", strlen(pattern));
	while(*input != '\0'){
		if(*input == *pattern){
			temp = input;
			for(int i=0; i<strlen(pattern); i++){
				if(*temp == pattern[i]){
					matching = 1;
					temp++;
				}else{
					matching = 0;
					input = temp;
				}
				if(matching){
					input++;
					position = input;
				}else{
					input++;
				}

			}
		}else{
			input++;
		}

	}



	return position;
}
