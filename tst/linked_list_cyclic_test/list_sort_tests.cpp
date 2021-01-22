#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_sort, empty_list_sort) {
    char **list = nullptr;
    StringListInit(&list);
    StringListSort(list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_sort, single_element_list_sort) {
    char **list = nullptr;
    StringListInit(&list);
    char element[] = "a";
    StringListAdd(list, element);
    StringListSort(list);
    char** arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[WORD], element);

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_sort, multiple_element_list_sort_sorted) {
    char **list = nullptr;
    StringListInit(&list);
    std::vector<std::string> words = {"a", "b", "c", "d"};
    for (auto & word: words) {
        StringListAdd(list, word);
    }

    StringListSort(list);
    char** arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    int i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_sort, multiple_element_list_sort_unsorted) {
    char **list = nullptr;
    StringListInit(&list);
    std::vector<std::string> words = {"c", "b", "a", "d"};
    for (auto & word: words) {
        StringListAdd(list, word);
    }

    StringListSort(list);
    std::sort(words.begin(), words.end());
    char** arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    int i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}


TEST(list_sort, multiple_element_list_sort_unsorted_duplicates) {
    char **list = nullptr;
    StringListInit(&list);
    std::vector<std::string> words = {"a", "h", "", " ", "c", "b", "a", "d"};
    for (auto & word: words) {
        StringListAdd(list, word);
    }

    StringListSort(list);
    std::sort(words.begin(), words.end());
    char** arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    int i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}