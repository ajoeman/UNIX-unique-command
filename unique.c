#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include<string.h>

int main(int argc, char* argv[]){
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
    list = addLine(list, line, argument);
    *line = line[0];
  }
  for(cur = list; cur->next != NULL; cur = cur->next){
    printf("%s\n", cur->line);
  }
 
}
