/****************************************************************************
 * unique.c accepts a list of strings from stdin and prints to stdout only *
 * the uniquely occurring strings. It can accept as a command either only  *
 * ./unique [filename] or ./unique f [filename]. If the f option is used,  *
 * unique will ignore the first f fields when considering whether two      *
 * strings are unique. f must be an integer between 0 and 9 inclusive. If  *
 * The command line arguments are invalid, unique will terminate. Else,    *
 * Unique uses the functions from list.c to add the unique strings to a    *
 * linked list and subsequently uses a loop to print to output the values  *
 * stored in the linked list. The function used to add lines to the list   *
 * accepts the command line argument as a parameter and calls the function *
 * match() to determine whether a string is unique before adding it to the *
 * list.                                                                   *
 * Declaration of academic integrity: This work is entirely my own.        *
 * However, I made use of idioms for parsing strings and linked lists which*
 * are described in C Programming: A Modern Approach, 2nd ed., by K.N.King.*
 * These idioms are denoted by single line comments where used.            *
 * Alex Manuele, B00559291, April 3, 2018.                                 *
 ***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include<string.h>

int main(int argc, char* argv[]){ //idiom from text
  int argument;
  if(argc > 2){
    printf("Illegal number of command line arguments.\n");
    exit(EXIT_FAILURE);
  }
  if(argc == 2){
    argument = atoi(argv[1]);
  }
  
  if(argument < 0 || argument > 9){
    printf("Illegal command line argument. f must be between 0 and 9.\n");
    exit(EXIT_FAILURE);
  }
  if(argc < 2){
    argument = -1;
  }
  
  char line[MAX_LINE_LENGTH + 1];
  int i = 1;
  struct node* list = NULL;
  struct node* cur;
  while(i != 0){
    i = getLine(line, MAX_LINE_LENGTH);
    if (i > 0){
       list = addLine(list, line, argument);
    }
    *line = line[0];
  }
  for(cur = list; cur->next != NULL; cur = cur->next){
    printf("%s\n", cur->line);
  }
  printf("%s\n", cur->line);
 
}
