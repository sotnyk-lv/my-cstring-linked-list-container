//
// Created by sotnyk on 21.12.20.
//

#ifndef LINKED_LIST_MYLINKEDLIST_H
#define LINKED_LIST_MYLINKEDLIST_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

/* Initializes list */
void StringListInit(char*** list);

void StringListInit(char*** list, char* word);
/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);
/* Inserts value at the end of the list. */
void StringListAdd(char** list, std::string str);
/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, std::string str);
/* Returns the number of items in the list. */
int StringListSize(char** list);
/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str);
/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list);
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);
/* Sorts the list of strings in ascending order */
void StringListSort(char** list);

void StringPrint(char** list);
inline int StringIsEmpty(char** list);

#endif //LINKED_LIST_MYLINKEDLIST_H
