# my-cstring-linked-list-container

This is small c-style implementation of ```CIRCULAR DOUBLE LINKED LIST``` container for c-strings.


## Author

- [Sahaidak Danylo](https://github.com/sotnyk-lv)

## Prerequisites

 - **C++ compiler** - needs to support **C++17** standard
 - **CMake** 3.17+

## [Interfase](https://github.com/sotnyk-lv/my-cstring-linked-list-container/blob/master/src/linked_cyclic_list/my_linked_cyclic_list.h)

```
/* Initializes src */
void StringListInit(char*** list);
```
```
/* Destroy src and set pointer to NULL. */
void StringListDestroy(char*** list);
```
```
/* Inserts value at the end of the src. */
void StringListAdd(char** list, std::string &str);
void StringListAdd(char** list, char* str);
```
```
/* Removes all occurrences of str in the src. */
void StringListRemove(char** list, std::string &str);
void StringListRemove(char** list, char* str);
```
```
/* Returns the number of items in the src. */
int StringListSize(char** list);
```
```
/* Returns the index position of the first occurrence of str in the src. */
int StringListIndexOf(char** list, char* str);
```
```
/* Removes duplicate entries from the src. */
void StringListRemoveDuplicates(char** list);
```
```
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);
```
```
/* Sorts the src of strings in ascending order */
void StringListSort(char** list);
```
