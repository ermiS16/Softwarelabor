/*
 * suffix.c
 *
 *  Created on: 07.11.2018
 *      Author: Eric
 */

#include "suffix.h"
#include "count.h"

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
	//Index fängt hinten bei Wort und Pattern an
	//zum zurücksetzen bei !matching
	int indexTmpI = indexI;
	int indexTmpP = indexP;

	//Wort muss existieren und noch kein matching
	while(indexI > 0 && !matching){
		indexTmpI = indexI;
		indexTmpP = indexP;
		//Pattern noch nicht erkannt
		//Vergleich von hinten.
		//Wenn indexP=0 dann pattern erkannt.
		while(!matching && (input[indexI] == pattern[indexP])){
			if(indexP == 0) matching = 1;
			indexI--;
			indexP--;
		}
		//Bei input[] != pattern[] Index zurücksetzen
		//Nächstes Zeichen von Input weitermachen.
		indexI = indexTmpI;
		indexP = indexTmpP;
		indexI--;
	}

	if(matching){
		//IndexInput wird um patternLength vergrößert
		for(int i = 0; i < patternLength; i++){
			indexI++;
		}
		//result = String hinter pattern.
		result = &input[indexI];
	}
	return result;
}


void extract2(char *input, char **output, char *pattern) {
	*output = extract(input, pattern);
}

