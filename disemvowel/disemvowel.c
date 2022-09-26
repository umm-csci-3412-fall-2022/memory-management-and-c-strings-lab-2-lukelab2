#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

//This method checks if a charcter is not a vowel. 
bool vowel(char l){
if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U') return true;
return false;
}

char *disemvowel(char *str) {
 //Length of original string
 int len = strlen(str);
 //Used in for loops
 int i;
 //New length of string
 int newlen = 0;
 //Current position in the string
 int pos = 0;
 char *result;
 for(i=0; i<len; ++i){
 if(vowel(str[i]) == false) newlen++;
 }
 if(newlen == 0) return (char*) "";
 result = (char*) calloc(newlen+1, sizeof(char));
    for (i=0; i<len; ++i) {
	if (vowel(str[i]) == false){
		result[pos] = str[i];
		pos++;
		}
	}
 result[newlen] = '\0';
 return result;
}
