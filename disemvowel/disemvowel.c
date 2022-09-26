#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
 int len = strlen(str);
 int i, pos = 0;
 char *result;
 result = (char*) calloc(len+1, sizeof(char));
    for (i=0; i<len; ++i) {
	if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
		result[pos] = str[i];
		pos++;
		}
	}
 result[len] = '\0';
 if (pos == 0){
	 free(result);
	 return (char*) "";
 }
 return result;
}
