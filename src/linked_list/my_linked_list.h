#ifndef LINKED_LIST_MYLINKEDLIST_H
#define LINKED_LIST_MYLINKEDLIST_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

/* Initializes src */
void StringListInit(char*** list);

void StringListInit(char*** list, char* word);
/* Destroy src and set pointer to NULL. */
void StringListDestroy(char*** list);
/* Inserts value at the end of the src. */
void StringListAdd(char** list, std::string str);
/* Removes all occurrences of str in the src. */
void StringListRemove(char** list, std::string str);
/* Returns the number of items in the src. */
int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the src. */
int StringListIndexOf(char** list, char* str);
/* Removes duplicate entries from the src. */
void StringListRemoveDuplicates(char** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);
/* Sorts the src of strings in ascending order */
void StringListSort(char** list);

void StringPrint(char** list);
inline int StringIsEmpty(char** list);

#endif //LINKED_LIST_MYLINKEDLIST_H
