#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_index_of, empty_list_index_of) {
    char **list = nullptr;
    StringListInit(&list);
    char value[] = "a";
    int index = StringListIndexOf(list, value);

    ASSERT_EQ(-1, index);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_index_of, single_element_list_index_of_not_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"b");
    char value[] = "a";
    int index = StringListIndexOf(list, value);

    ASSERT_EQ(index, -1);
    ASSERT_EQ(StringListSize(list), 1);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "b");


    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_index_of, single_element_list_index_of_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"a");
    char value[] = "a";
    int index = StringListIndexOf(list, value);

    ASSERT_EQ(index, 0);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "a");


    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_index_of, multiple_elements_list_index_of_not_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"a");
    StringListAdd(list, (char*)"b");
    StringListAdd(list, (char*)"c");
    StringListAdd(list, (char*)"d");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"e");
    char value[] = "f";
    int index = StringListIndexOf(list, value);

    ASSERT_EQ(index, -1);

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

TEST(list_index_of, multiple_elements_list_index_of_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"a");
    StringListAdd(list, (char*)"b");
    StringListAdd(list, (char*)"c");
    StringListAdd(list, (char*)"d");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"e");
    char value_a[] = "a";
    char value_b[] = "b";
    char value_c[] = "c";
    char value_d[] = "d";
    char value_[] = "";
    char value_e[] = "e";
    int index_a = StringListIndexOf(list, value_a);
    int index_b = StringListIndexOf(list, value_b);
    int index_c = StringListIndexOf(list, value_c);
    int index_d = StringListIndexOf(list, value_d);
    int index_ = StringListIndexOf(list, value_);
    int index_e = StringListIndexOf(list, value_e);


    ASSERT_EQ(index_a, 0);
    ASSERT_EQ(index_b, 1);
    ASSERT_EQ(index_c, 2);
    ASSERT_EQ(index_d, 3);
    ASSERT_EQ(index_, 4);
    ASSERT_EQ(index_e, 5);

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