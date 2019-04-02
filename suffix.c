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


void extract2(char *input, char **output, char *pattern) {
	*output = extract(input, pattern);
}

