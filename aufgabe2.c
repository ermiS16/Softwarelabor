/*
 * aufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: Eric
 */

#include "aufgabe2.h"

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
//char* extract(char *input, char *pattern) {
//	char *position = input;
//	char patternChar = *pattern;
//	char inputChar = *input;
//	int inputLength = 0;
//	int indexI;
//	int indexP;
//	int patternLength = 0;
//	int matching = 1;
//	//Count InputLength
//	while (inputChar != '\0') {
//		inputLength++;
//		inputChar = input[inputLength];
//	}
//	indexI = inputLength - 1;
//	//Count Patternlength
//	while (patternChar != '\0') {
//		patternLength++;
//		patternChar = pattern[patternLength];
//	}
//	indexP = patternLength - 1;
//	//	Pattern Matching
//	while (indexI > 0) {
//
//		if (input[indexI] == pattern[indexP]) {
//			for (int i = 0; i < patternLength; i++) {
//				if (input[indexI] == pattern[indexP]) {
//					if (indexI > 0) {
//						indexI--;
//					}
//					if (indexP > 0) {
//						indexP--;
//					}
//					matching = 1;
//				} else {
//					indexP = patternLength;
//					indexI--;
//					matching = 0;
//				}
//			}
//		}
//		if (indexP == 0 && matching == 1) {
//			for (int i = 0; i <= indexI + patternLength; i++) {
//				input++;
//			}
//			indexI=0;
//		}
//		position = input;
//		indexI--;
//	}
//	return position;
//}

/*
 char* extract(char *input, char *pattern) {
 int length = 0;
 while (input[length] != 0) {
 length++;
 }

 //Find last :
 int doubleCounter = 0;
 while (doubleCounter < 2) {
 while (input[length] != ':') {
 while()
 }
 }
 }
 }
 */

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

