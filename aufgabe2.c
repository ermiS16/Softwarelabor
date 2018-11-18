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
	printf("String: %s\n", input);

	while(*input != '\0'){
		if(*input == *pattern){
			temp = input;
			for(int i=0; i<sizeof(pattern); i++){
				if(*temp == pattern[i]){
					matching = 1;
				}else{
					matching = 0;
					input = temp;
				}
				if(matching){
					position = input+1;
				}
				input++;
			}
		}
		input++;
	}



	return position;
}
