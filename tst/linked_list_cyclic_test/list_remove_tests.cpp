#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_remove, empty_list_remove) {
    char **list = nullptr;
    StringListInit(&list);
    StringListRemove(list, (char*)"odd");

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_remove, single_element_list_remove_not_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"odd");
    StringListRemove(list, (char*)"od");

    ASSERT_EQ(StringListSize(list), 1);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_STREQ(arr[0], "odd");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove, single_element_list_remove_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"odd");
    StringListRemove(list, (char*)"odd");

    ASSERT_EQ(StringListSize(list), 0);
    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[WORD], "");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove, multiple_element_list_remove_not_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"odd");
    StringListAdd(list, (char*)"add");
    StringListAdd(list, (char*)"sub");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"dodd");

    StringListRemove(list, (char*)"dd");

    ASSERT_EQ(StringListSize(list), 5);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "odd");
    ASSERT_STREQ(arr[1], "add");
    ASSERT_STREQ(arr[2], "sub");
    ASSERT_STREQ(arr[3], "");
    ASSERT_STREQ(arr[4], "dodd");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove, multiple_element_list_remove_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"dd");
    StringListAdd(list, (char*)"odd");
    StringListAdd(list, (char*)"add");
    StringListAdd(list, (char*)"sub");
    StringListAdd(list, (char*)"dd");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"dodd");

    StringListRemove(list, (char*)"dd");

    ASSERT_EQ(StringListSize(list), 5);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "odd");
    ASSERT_STREQ(arr[1], "add");
    ASSERT_STREQ(arr[2], "sub");
    ASSERT_STREQ(arr[3], "");
    ASSERT_STREQ(arr[4], "dodd");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}

TEST(list_remove, multiple_element_list_remove_string) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, (char*)"dd");
    StringListAdd(list, (char*)"odd");
    StringListAdd(list, (char*)"add");
    StringListAdd(list, (char*)"sub");
    StringListAdd(list, (char*)"dd");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"dodd");

    std::string rem_str = "dd";
    StringListRemove(list, rem_str);

    ASSERT_EQ(StringListSize(list), 5);

    char **arr;
    StringListToString(list, &arr);

    ASSERT_TRUE(arr != nullptr);
    ASSERT_STREQ(arr[0], "odd");
    ASSERT_STREQ(arr[1], "add");
    ASSERT_STREQ(arr[2], "sub");
    ASSERT_STREQ(arr[3], "");
    ASSERT_STREQ(arr[4], "dodd");

    free_string_array(arr, StringListSize(list));
    StringListDestroy(&list);
}