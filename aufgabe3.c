/*
 * aufgabe3.c
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#include "aufgabe3.h"
#include "aufgabe2.h"

int breakIntoWords(char *line, int maxwords, char *words[]){
	int newWord = 1;
	int wordIndex = 0;
	char *linePtr = line;

	while(line != '\0'){
		while(line[0] == ' '){
			newWord = 1;
			line++;
//			index++;
		}
		if(line[0] != ' ' && line[0] != '\0'){
			if(newWord){
				words[wordIndex] = line;
				wordIndex++;
				newWord = 0;
			}
		}
		line++;
	}
	return wordIndex;
}
