#include "my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

void StringListInit(char*** list) {
    char** curr_node = (char**)malloc(3*sizeof(char*));
    curr_node[WORD] = nullptr;
    curr_node[NEXT_NODE] = reinterpret_cast<char *>(curr_node);
    curr_node[PREV_NODE] = reinterpret_cast<char *>(curr_node);
    *list = curr_node;
}

void StringListDestroy(char*** list) {
    char** curr_node = *list;
    curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    while (curr_node[WORD] != nullptr)
    {
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
        DeleteNode(reinterpret_cast<char **>(curr_node[PREV_NODE]));
    }
    free(curr_node);
}

void StringListAdd(char** list, std::string str) {

    char** last_node = reinterpret_cast<char **>(list[PREV_NODE]);

    char** new_node = (char**) malloc(3 * sizeof(char**));

    char* word = (char*) malloc(str.length() * sizeof(char));
    strcpy(word, str.c_str());
    new_node[WORD] = word;

    new_node[NEXT_NODE] = reinterpret_cast<char *>(list);
    new_node[PREV_NODE] = reinterpret_cast<char *>(last_node);
    last_node[NEXT_NODE] = reinterpret_cast<char *>(new_node);
    list[PREV_NODE] = reinterpret_cast<char *>(new_node);

}

void StringListAdd(char** list, char* str) {

    char** last_node = reinterpret_cast<char **>(list[PREV_NODE]);

    char** new_node = (char**) malloc(3 * sizeof(char**));

    char* word = (char*) malloc(strlen(str) * sizeof(char));
    strcpy(word, str);
    new_node[WORD] = word;

    new_node[NEXT_NODE] = reinterpret_cast<char *>(list);
    new_node[PREV_NODE] = reinterpret_cast<char *>(last_node);
    last_node[NEXT_NODE] = reinterpret_cast<char *>(new_node);
    list[PREV_NODE] = reinterpret_cast<char *>(new_node);

}

void StringPrint(char** list) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    while (curr_node[WORD] != nullptr)
    {
//        std::cout << curr_node[PREV_NODE][WORD] << "-" << curr_node[WORD] << "-" << curr_node[NEXT_NODE][WORD] << std::endl;
        std::cout << curr_node[WORD] << std::endl;
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    }
}

void DeleteNode(char** node) {
    char** next_node = reinterpret_cast<char **>(node[NEXT_NODE]);
    char** prev_node = reinterpret_cast<char **>(node[PREV_NODE]);
    next_node[PREV_NODE] = reinterpret_cast<char *>(prev_node);
    prev_node[NEXT_NODE] = reinterpret_cast<char *>(next_node);
    free(node[WORD]);
    free(node);
}


void StringListRemove(char** list, std::string str) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    while (curr_node[WORD] != nullptr)
    {
        if (((curr_node[WORD]) != nullptr) && (strcmp(str.c_str(), curr_node[WORD]) == 0)) {
            curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
            DeleteNode(reinterpret_cast<char **>(curr_node[PREV_NODE]));
        }
        else {
            curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
        }
    }
}

void StringListRemove(char** list, char* str) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    while (curr_node[WORD] != nullptr)
    {
        if (((curr_node[WORD]) != nullptr) && (strcmp(str, curr_node[WORD]) == 0)) {
            curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
            DeleteNode(reinterpret_cast<char **>(curr_node[PREV_NODE]));
        }
        else {
            curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
        }
    }
}

int StringListSize(char** list) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    int len = 0;
    while (curr_node[WORD] != nullptr)
    {
        len++;
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);

    }
    return len;
}

int StringListIndexOf(char** list, char* str) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    int i = 0;
    while (curr_node[WORD] != nullptr) {
        if (((curr_node[WORD]) != nullptr) && (strcmp(str, curr_node[WORD]) == 0)) {
            return i;
        }
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
        i++;
    }
    return -1;
}

void StringListRemoveDuplicates(char** list) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    while (curr_node[WORD] != nullptr) {
        StringListRemove(curr_node, curr_node[WORD]);
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    while (curr_node[WORD] != nullptr) {
        if (((curr_node[WORD]) != nullptr) && (strcmp(before, curr_node[WORD]) == 0)) {
            free(curr_node[WORD]);
            char* new_word = (char*) malloc(strlen(after)* sizeof(char));
            strcpy(new_word, after);
            curr_node[WORD] = new_word;
        }
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    }
}

void SwapNodes(char** first, char** second) {
    char* new_first_word = (char*) malloc(strlen(second[WORD])* sizeof(char));
    strcpy(new_first_word, second[WORD]);
    char* new_second_word = (char*) malloc(strlen(first[WORD])* sizeof(char));
    strcpy(new_second_word, first[WORD]);
    free(first[WORD]);
    free(second[WORD]);
    first[WORD] = new_first_word;
    second[WORD] = new_second_word;
}

void StringListSort(char** list) {
    bool if_done = false;
    char** first = reinterpret_cast<char **>(list[NEXT_NODE]);
    char** second = reinterpret_cast<char **>(first[NEXT_NODE]);

    if (second[WORD] == nullptr) return;

    while (!if_done) {
        first = reinterpret_cast<char **>(list[NEXT_NODE]);
        second = reinterpret_cast<char **>(first[NEXT_NODE]);
        if_done = true;
        while (second[WORD] != nullptr) {
            if ( strcmp(first[WORD], second[WORD]) > 0) {
                SwapNodes(first, second);
                if_done = false;
            }
            first = second;
            second = reinterpret_cast<char **>(first[NEXT_NODE]);
        }
    }
}

void StringListToString(char** list, char** res) {
    char** curr_node = reinterpret_cast<char **>(list[NEXT_NODE]);
    res = (char**) malloc(StringListSize(list) * sizeof(char*));
    long i = 0;
    while (curr_node[WORD] != nullptr) {
        char* curr_word = (char*) malloc(strlen(curr_node[WORD]) * sizeof(char*));
        strcpy(curr_word, curr_node[WORD]);
        res[i] = curr_word;
        curr_node = reinterpret_cast<char **>(curr_node[NEXT_NODE]);
    }
}


