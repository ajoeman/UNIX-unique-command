#include "match.h"

Bool match(char s1[], char s2[]){ //Returns true if string1 and string2 match.
  if (strcmp(s1, s2) == 0){
    return TRUE;
  }
  return FALSE;
}
