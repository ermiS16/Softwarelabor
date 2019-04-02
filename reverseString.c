/*
 * reverseString.c
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#include "reverseString.h"
#include "count.h"

char *reverse(char *s){
	int length = stringLength(s);
	char *reverse = (char *) malloc(sizeof(char) * length);
	if(length>0){
		int k = length-1;
		for(int i=0; i<length; i++, k--){
			reverse[i] = s[k];
		}
	}else{
		reverse = "";
	}
	return reverse;
}
