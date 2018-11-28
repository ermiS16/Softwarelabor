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
	printf("Pattern length: %d\n",(int) strlen(pattern));

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


void extract2(char *input, char **output, char *pattern){
	*output = extract(input, pattern);
}


// Ueberspringe alle Leerzeichen
// Rueckgabe ist Zeiger auf das erste Nichtleerzeichen
char* leerzeichen(char* input) {
  while(*input == ' ')
    input++;
  return input;
}

// Scanne durch string solange bis wir auf ein
// Leerzeichen oder das Ende des Strings treffen.
// Effektiv ueberspringen wir ein Wort.
// Rueckgabe: Zeiger auf Ende oder Leerzeichen.
char* zeichen(char* input) {
  while(*input != '\0' && *input != ' ')
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

  while(*input != '\0') {
    input = leerzeichen(input);
    if(*input != '\0') {
      cnt++;
      input = zeichen(input);
    }
  }
  return cnt;
}

