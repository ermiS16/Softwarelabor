/*
 * count.c
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#include "count.h"


int stringLength(char *s){
	int length = 0;
	while(*s != '\0'){
		length++;
		s++;
	}
	return length;
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
