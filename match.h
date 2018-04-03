#ifndef MATCH_H
#define MATCH_H
#define TRUE 1
#define FALSE 0
typedef int Bool;
#include<string.h>
/**********************************************************************
 * match: Determines whether two strings passed into the function     *
 * are a lexicographic match. Calls getFields to determine whether    *
 *  fields should be ignored. Returns 1 if strings match, 0 otherwise.*
 **********************************************************************/
Bool match(char s1[], char s2[], int arg);
#endif

/**********************************************************************
 * getFields: uses a char* point to point at the start of the string  *
 * passed as a paramter. If arg is -1, simply returns a pointer to the*
 * first character of the parameter string. Otherwise, uses a loop to *
 * to point to the first char of the (f+1)th field of the parameter   *
 * string and returns that pointer.                                   *
 **********************************************************************/
char* getFields(char s[], int arg);

