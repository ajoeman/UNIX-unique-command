#include "match.h"

Bool match(char s1[], char s2[], int arg){ //Returns true if string1 and string2 match.
  /* int length1 = strlen(s1) + 1;//strlen doesnt count the null token
     int length2 = strlen(s2) + 1; */
  char* string1;
  char* string2;
  string1 = getFields(s1, arg);
  string2 = getFields(s2, arg);
  if (strcmp(string1, string2) == 0){
    return TRUE;
  }
  return FALSE;
}

/*Write a function that will accept as input the number of fields to be
 * extracted and produces as output a string containing those fields.
 *Change match() so that accepts an int as a parameter and then passes
 *s1 and s2 through the fields() function before comparing.*/
char* getFields(char s[], int arg){
  char* p = s;
  int i = 0;
  if(arg == -1){ //unique will pass -1 if command line option wasn't used
    return p;
  }else{
    while(*p && i < arg){
      if(p[0] == ' '){
	i++;
	while(p[0] == ' ')
	  p++;
      }
      else
        p++;
    }
  }
    return p;
}
