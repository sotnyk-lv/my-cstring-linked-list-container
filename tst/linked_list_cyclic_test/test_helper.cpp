#include "test_helper.h"

void free_string_array(char** arr, int size) {
    if (size == 0) {
        free(arr[0]);
        arr[0] = nullptr;
    }
    for (int i=0; i < size; ++i) {
        free(arr[i]);
        arr[i] = nullptr;
    }
    free(arr);
    arr = nullptr;
}