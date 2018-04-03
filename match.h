#ifndef MATCH_H
#define MATCH_H
#define TRUE 1
#define FALSE 0
typedef int Bool;
#include<string.h>
/**********************************************************************
 * match: Determines whether two strings passed into the function     *
 * are a lexicographic match. Returns 1 if strings match, 0 otherwise.*
 **********************************************************************/
Bool match(char s1[], char s2[], int arg);
#endif

char* getFields(char s[], int arg);

