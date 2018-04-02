#include<stdio.h>
#include<stdlib.h>
#include "lines.h"

int main(void){
  char line[MAX_LINE_LENGTH + 1];
  int i = 1;
  struct node* list = NULL;
  struct node* cur;
  while(i != 0){
    i = getLine(line, MAX_LINE_LENGTH);
    list =  addLine(list, line);
    *line = line[0];
  }
  for(cur = list; cur->next != NULL; cur = cur->next){
    printf("%s\n", cur->line);
  }
 
}
