#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include "match.h"


int getLine (char str[], int n){
  int ch, i;
  i = 0;
  while((ch = getchar()) != '\n' && ch != EOF){ //idiom from course text
    if(i< n){
      str[i++] = ch;
    }
  }
   if(i == (n)){
    printf("Error: input line(s) exceed maximum line length\n");
    printf("last string stored was %s.\n", str);
    exit(EXIT_FAILURE); //program terminates if line is longer than 80 chars
    }
   
  str[i] = '\0';
  return i; //The function returns the number of chars written to the line
}

 
struct node* addLine(struct node* list, char line[], int arg){
  struct node* cur = list;
  struct node* entry;
  entry = malloc(sizeof(struct node));
  if (cur == NULL){  //list is empty 
    strcpy(entry->line, line);
    entry->next = NULL;
    list = entry;
  }else{
    for(; cur->next != NULL; cur = cur->next){ //idiom from text p430
      if(match((cur->line), line, arg)){
	 goto end; //end the function if a match is found.
       }
    }
    if(match((cur->line), line, arg)){
	goto end;
     }
    strcpy(entry->line, line);
    entry->next = NULL;
    cur->next = entry;
  }
 end: return list;
}
  
  



