#include <string>
#include <vector>
#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_to_array, empty_list_to_array) {
    char **list = nullptr;
    StringListInit(&list);
    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) == list);

    ASSERT_TRUE(arr != nullptr);
    //    ASSERT_TRUE(arr[WORD] == nullptr); // -just run
    ASSERT_STREQ(arr[WORD], ""); // -valgrind

    free_string_array(arr, StringListSize(list));

    StringListDestroy(&list);
}

TEST(list_to_array, single_element_list_to_array) {
    char **list = nullptr;
    StringListInit(&list);
    char element[] = "new_string";
    StringListAdd(list, element);
    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[WORD], element);

    free_string_array(arr, StringListSize(list));

    StringListDestroy(&list);
}

TEST(list_to_array, multiple_element_list_to_array) {
    char **list = nullptr;
    StringListInit(&list);
    char element[] = "new_string";
    StringListAdd(list, element);
    StringListAdd(list, element);
    StringListAdd(list, (char*)"element");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"0");
    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "new_string");
    ASSERT_STREQ(arr[1], "new_string");
    ASSERT_STREQ(arr[2], "element");
    ASSERT_STREQ(arr[3], "");
    ASSERT_STREQ(arr[4], "0");

    free_string_array(arr, StringListSize(list));

    StringListDestroy(&list);
}