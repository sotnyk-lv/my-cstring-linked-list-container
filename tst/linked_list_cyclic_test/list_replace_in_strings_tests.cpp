#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_replace_in_strings, empty_list_replace_in_strings) {
    char **list = nullptr;
    StringListInit(&list);
    char before[] = "a";
    char after[] = "b";
    StringListReplaceInStrings(list, before, after);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_replace_in_strings, empty_list_replace_in_strings_same_element) {
    char **list = nullptr;
    StringListInit(&list);
    char before[] = "a";

    StringListReplaceInStrings(list, before, before);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_replace_in_strings, single_element_list_replace_in_strings) {
    char **list = nullptr;
    StringListInit(&list);
    char before[] = "a";
    char after[] = "b";
    StringListAdd(list, before);

    ASSERT_EQ(StringListSize(list), 1);

    StringListReplaceInStrings(list, before, after);

    ASSERT_EQ(StringListSize(list), 1);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "b");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_replace_in_strings, multiple_element_list_replace_in_strings) {
    char **list = nullptr;
    StringListInit(&list);
    char before[] = "a";
    char after[] = "b";
    StringListAdd(list, before);
    StringListAdd(list, before);
    StringListAdd(list, before);
    StringListAdd(list, after);
    StringListAdd(list, (char*)"c");
    StringListAdd(list, (char*)"d");

    ASSERT_EQ(StringListSize(list), 6);

    StringListReplaceInStrings(list, before, after);

    ASSERT_EQ(StringListSize(list), 6);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "b");
    ASSERT_STREQ(arr[1], "b");
    ASSERT_STREQ(arr[2], "b");
    ASSERT_STREQ(arr[3], "b");
    ASSERT_STREQ(arr[4], "c");
    ASSERT_STREQ(arr[5], "d");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}