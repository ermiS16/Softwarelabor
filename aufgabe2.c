/*
 * aufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: Eric
 */

#include "aufgabe2.h"
/**
 * Extracts a String, that contains the Characters following the pattern.
 * @param input String in which to search for the pattern
 * @param pattern The Pattern to search for.
 * return char* of the first Character, that follows the pattern.
 */
char *extract(char *input, char *pattern){
	char *result = input;
	int inputLength = stringLength(input);
	int patternLength = stringLength(pattern);
	int indexI = inputLength-1;
	int indexP = patternLength-1;
	int matching = 0;
	int indexTmpI = indexI;
	int indexTmpP = indexP;

	while(indexI > 0 && !matching){
		indexTmpI = indexI;
		indexTmpP = indexP;
		while(!matching && input[indexI] == pattern[indexP]){
			if(indexP == 0) matching = 1;
			indexI--;
			indexP--;
		}
		indexI = indexTmpI;
		indexP = indexTmpP;
		indexI--;
	}

	if(matching){
		for(int i = 0; i < patternLength; i++){
			indexI++;
		}
		result = &input[indexI];
	}
	return result;
}

int stringLength(char *s){
	int length = 0;
	while(*s != '\0'){
		length++;
		s++;
	}
	return length;
}

void extract2(char *input, char **output, char *pattern) {
	*output = extract(input, pattern);
}

// Ueberspringe alle Leerzeichen
// Rueckgabe ist Zeiger auf das erste Nichtleerzeichen
char* leerzeichen(char* input) {
	while (*input == ' ')
		input++;
	return input;
}

// Scanne durch string solange bis wir auf ein
// Leerzeichen oder das Ende des Strings treffen.
// Effektiv ueberspringen wir ein Wort.
// Rueckgabe: Zeiger auf Ende oder Leerzeichen.
char* zeichen(char* input) {
	while (*input != '\0' && *input != ' ')
		input++;
	return input;
}

int count(char* input) {
	int cnt = 0;

// Solange das Ende nicht erreicht ist:
// 1. Ueberspringe alle Leerzeichen
// 2. Falls Zeichen gefunden
//     (a) setze Zaehler hoch
//     (b) Gehe zu Wortende

	while (*input != '\0') {
		input = leerzeichen(input);
		if (*input != '\0') {
			cnt++;
			input = zeichen(input);
		}
	}
	return cnt;
}

