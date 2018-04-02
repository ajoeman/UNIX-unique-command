#include<stdio.h>
#include<stdlib.h>
#include "lines.h"
#include "match.h"


int getLine (char str[], int n){
  int ch, i;
  i = 0;
  while((ch = getchar()) != '\n' && ch != EOF){
    if(i< n){
      str[i++] = ch;
    }
  }
   if(i == (n-1)){
    printf("Error: input line(s) exceed maximum line length\n");
    printf("last string stored was %s.\n", str);
    exit(EXIT_FAILURE); //program terminates if line is longer than 80 chars
    }
   
  str[i] = '\0';
  return i; //The function returns the number oof chars written to the line
}

 
struct node* addLine(struct node* list, char line[]){
  struct node* cur;
  struct node* entry;
  entry = malloc(sizeof(struct node));
  for(cur = list; cur->next != NULL; cur = cur->next){ //idiom from p430 of text
       if(match((cur->line), line)){
	free(entry); //release the memory allocated for the entry.
	break; 
       }
  }

  if (cur == NULL){   
    strcpy(entry->line, line);
    entry->next = NULL;
    list = entry;
  }
  else{
    strcpy(entry->line, line);
    entry->next = NULL;
    cur->next = entry;
    
  }
  return list;
}
  
  



