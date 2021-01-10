#include "my_linked_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2



void StringListInit(char*** list) {
    char** curr_node = (char**)malloc(3*sizeof(char*));
    curr_node[WORD] = nullptr;
    curr_node[NEXT_NODE] = nullptr;
    curr_node[PREV_NODE] = nullptr;
    *list = curr_node;
};

void StringListInit(char*** list, char* word) {
    char** curr_node = (char**)malloc(3*sizeof(char*));
    curr_node[WORD] = word;
    curr_node[NEXT_NODE] = nullptr;
    curr_node[PREV_NODE] = nullptr;
    *list = curr_node;

};

void StringListDestroy(char** list) {

};

void StringListAdd(char** list, std::string str) {
    if (StringIsEmpty(list)) {

        char *word = (char*) malloc(str.length() * sizeof(char));
        strcpy(word, str.c_str());
        list[WORD] = word;

    }
    else {
        char** last_node = list;
        while (last_node[NEXT_NODE] != nullptr) {
            last_node = reinterpret_cast<char **>(last_node[NEXT_NODE]);
        }
        char** new_node = (char**) malloc(3 * sizeof(char**));

        char* word = (char*) malloc(str.length() * sizeof(char));
        strcpy(word, str.c_str());
        new_node[WORD] = word;

        new_node[NEXT_NODE] = nullptr;
        new_node[PREV_NODE] = reinterpret_cast<char *>(last_node);
        last_node[NEXT_NODE] = reinterpret_cast<char *>(new_node);
    }

};

void StringPrint(char** list) {
    if (StringIsEmpty(list)) {
        std::cout << "empty src" << std::endl;
        return;
    }
    char** curr_node = list;
    do {
        std::cout << curr_node[WORD] << std::endl;
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    }
    while (curr_node[NEXT_NODE] != nullptr);
}

inline int StringIsEmpty(char** list) {
    if (list[WORD] == nullptr ) {
        return 1;
    }
    return 0;
}

void StringListRemove(char** list, std::string str) {
    if (list[WORD] == nullptr ) {
        return;
    }
    if ((list[PREV_NODE] == nullptr) && (list[NEXT_NODE] == nullptr) && (strcmp(str.c_str(), list[WORD]) != 0)) {
        free(list[WORD]);
        list[WORD] = nullptr;
    }
    do {
            std::cout << "deleting " << list[WORD] << std::endl;
            if ((list[PREV_NODE] == nullptr) && (list[NEXT_NODE] == nullptr)) {
                char** prev_node = reinterpret_cast<char **>(list[PREV_NODE]);
                prev_node[NEXT_NODE] = list[NEXT_NODE];
            }

    }
    while (list[NEXT_NODE] != nullptr);

//    int strcmp (const char* str1, const char* str2);
}


