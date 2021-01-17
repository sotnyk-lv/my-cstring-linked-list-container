#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_remove_duplicates, empty_list_remove_duplicates) {
    char **list = nullptr;
    StringListInit(&list);
    StringListRemoveDuplicates(list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_remove_duplicates, single_element_list_remove_duplicates) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"b");
    StringListRemoveDuplicates(list);

    ASSERT_EQ(StringListSize(list), 1);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "b");


    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove_duplicates, multiple_element_list_remove_duplicates_no_duplicates) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"a");
    StringListAdd(list, (char*)"b");
    StringListAdd(list, (char*)"c");
    StringListAdd(list, (char*)"d");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"e");

    StringListRemoveDuplicates(list);

    ASSERT_EQ(StringListSize(list), 6);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "a");
    ASSERT_STREQ(arr[1], "b");
    ASSERT_STREQ(arr[2], "c");
    ASSERT_STREQ(arr[3], "d");
    ASSERT_STREQ(arr[4], "");
    ASSERT_STREQ(arr[5], "e");


    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove_duplicates, multiple_element_list_remove_duplicates) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"a");
    StringListAdd(list, (char*)"b");
    StringListAdd(list, (char*)"c");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"d");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"e");
    StringListAdd(list, (char*)"e");
    StringListAdd(list, (char*)"b");

    ASSERT_EQ(StringListSize(list), 10);

    StringListRemoveDuplicates(list);

    ASSERT_EQ(StringListSize(list), 6);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "a");
    ASSERT_STREQ(arr[1], "b");
    ASSERT_STREQ(arr[2], "c");
    ASSERT_STREQ(arr[3], "");
    ASSERT_STREQ(arr[4], "d");
    ASSERT_STREQ(arr[5], "e");


    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}