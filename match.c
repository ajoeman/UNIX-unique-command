#include "match.h"

Bool match(char s1[], char s2[], int arg){ 
  char* string1; 
  char* string2;
  string1 = getFields(s1, arg);
  //now string1 is == s1 with the first arg fields removed.
  string2 = getFields(s2, arg);
  if (strcmp(string1, string2) == 0){ //compares the extracted fields
    return TRUE;
  }
  return FALSE;
}


char* getFields(char s[], int arg){
  char* p = s;
  int i = 0;
  if(arg == -1){ //unique will pass -1 if command line option wasn't used
    return p;
  }else{ //valid arg input is handled by unique.c
    while(*p && i < arg){ //stops if p* points to NULL
      if(p[0] == ' '){
	i++; //i counts the fields.
	while(p[0] == ' ')//skips all the whitespace between two fields.
	  p++;
      }
      else
        p++; //p increments one character if a whitespace wasnt encountered
    }
  }
  return p; //returns a pointer to the first charcter of the (f+1)th field.
}
