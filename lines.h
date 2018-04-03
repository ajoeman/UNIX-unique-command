#ifndef LINES_H
#define LINE_H
#define MAX_LINE_LENGTH 80
/***************************************************************************
 * lines.c uses a linked list composed of nodes to store the unique strings*
 * from stdin. The node structure is declared below. The structure for node*
 * was based from the linked list described in section 17.5 of the course  *
 * text. Each node contains a String and a pointer to the subsequent node  *
 * in the linked list.                                                     *
 **************************************************************************/
struct node{ 
  char line[MAX_LINE_LENGTH + 1];
  struct node* next;
};
/****************************************************************************
 * getLine() reads a line from stdin character by character and places each *
 * character into a string (an array of characters).The function loops      *
 * until it encounters a new line character or EOF. If the line read exceeds*
 * the MAX_LINE_LENGTH, the program terminates. The function returns the    * 
 * number of characters input into the line, a feature not used in this     *
 * project but which improves code reusability.                             *
 ****************************************************************************/
int getLine(char str[], int n);

/***************************************************************************
 * The function addLine() adds a new node to a linked list if the value in *
 * that node does not already exist in the list. it parses the list until  *
 * it either finds a match to the input value or reaches the NULL pointer  *
 * found at the end of the list. If it finds a match, it frees the memory  *
 * that was allocated for the new node and exits the loop. If it reaches   *
 * the end of the list without finding a match, it initializes a Node with *
 * the value of line and points the last node in the list to it.           *
 ***************************************************************************/
struct node* addLine(struct node* list, char line[], int arg);
#endif
