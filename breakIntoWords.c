/*
 * breakIntoWords.c
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#include "breakIntoWords.h"

#include "suffix.h"

int breakIntoWords(char *line, int maxwords, char *words[]){
	int newWord = 1;
	int wordIndex = 0;

	//Maxwords nicht erreicht UND es gibt noch Wörter
	while(wordIndex < maxwords && (*line != '\0')){

		//Bei Leetzeichen, diese durch \0 ersetzen
		while(*line == ' '){
			newWord = 1;
			*line = '\0';
			line++;
		}

		//Wenn neues Wort, dann Anfangsadresse des Wortes in words[] speichern.
		if(*line != ' ' && (*line != '\0')){
			if(newWord){
				words[wordIndex] = line;
				wordIndex++;
				newWord = 0;
			}
		}

		//Wenn Maxword erreicht, dann gehe ans Ende vom Wort und setze nulltermianl
		if(wordIndex == maxwords){
			while(*line != ' '){
				line++;
			}
			*line = '\0';
		}
		line++;
	}
	return wordIndex;
}
