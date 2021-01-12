#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

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

TEST(list_creation, empty_list_creation) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_size, single_element_list_size) {
    char **list = nullptr;
    StringListInit(&list);
    char element[] = "new_string";
    StringListAdd(list, element);

    ASSERT_EQ(StringListSize(list), 1);

    StringListDestroy(&list);
}

TEST(list_size, multiple_element_list_size) {
    char **list = nullptr;
    StringListInit(&list);
    ASSERT_EQ(StringListSize(list), 0);
    char element[] = "new_string";
    StringListAdd(list, element);
    ASSERT_EQ(StringListSize(list), 1);
    StringListAdd(list, element);
    ASSERT_EQ(StringListSize(list), 2);
    StringListAdd(list, "super_new_string");
    ASSERT_EQ(StringListSize(list), 3);

    StringListDestroy(&list);
}

TEST(list_size, empty_list_size) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_EQ(StringListSize(list), 0);

    StringListDestroy(&list);
}

TEST(list_element_adding, add_single_element_to_empty_list) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) == list);

    char element[] = "new_string";
    StringListAdd(list, element);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[WORD]) == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) != nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) != nullptr);
    ASSERT_STREQ(reinterpret_cast<char **>(list[NEXT_NODE])[WORD], element);
    ASSERT_STREQ(reinterpret_cast<char **>(list[PREV_NODE])[WORD], element);
    ASSERT_EQ(reinterpret_cast<char **>(list[NEXT_NODE]), reinterpret_cast<char **>(list[PREV_NODE]));
    ASSERT_TRUE(reinterpret_cast<char **>(reinterpret_cast<char **>(list[NEXT_NODE])[NEXT_NODE])[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(reinterpret_cast<char **>(list[PREV_NODE])[PREV_NODE])[WORD] == nullptr);

    StringListDestroy(&list);
}

TEST(list_element_adding, add_single_string_element_to_empty_list) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) == list);

    std::string element = "new_element";
    StringListAdd(list, element);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[WORD]) == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) != nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) != nullptr);
    ASSERT_STREQ(reinterpret_cast<char **>(list[NEXT_NODE])[WORD], element.c_str());
    ASSERT_STREQ(reinterpret_cast<char **>(list[PREV_NODE])[WORD], element.c_str());
    ASSERT_EQ(reinterpret_cast<char **>(list[NEXT_NODE]), reinterpret_cast<char **>(list[PREV_NODE]));
    ASSERT_TRUE(reinterpret_cast<char **>(reinterpret_cast<char **>(list[NEXT_NODE])[NEXT_NODE])[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(reinterpret_cast<char **>(list[PREV_NODE])[PREV_NODE])[WORD] == nullptr);

    StringListDestroy(&list);
}

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
    StringListAdd(list, "element");
    StringListAdd(list, "");
    StringListAdd(list, "0");
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

TEST(list_print, empty_list_print) {
    testing::internal::CaptureStdout();

    char **list = nullptr;
    StringListInit(&list);
    StringPrint(list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) == list);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");

    StringListDestroy(&list);
}

TEST(list_print, one_element_list_print) {
    testing::internal::CaptureStdout();

    char **list = nullptr;
    StringListInit(&list);
    char element[] = "new_string";
    StringListAdd(list, element);
    StringPrint(list);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "new_string\n");

    StringListDestroy(&list);
}

TEST(list_print, multiple_element_list_print) {
    testing::internal::CaptureStdout();

    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, "first_string");
    StringListAdd(list, "second_string");
    StringListAdd(list, "");
    StringListAdd(list, "fourth_string");
    StringPrint(list);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "first_string\nsecond_string\n\nfourth_string\n");

    StringListDestroy(&list);
}

TEST(list_remove, empty_list_remove) {
    char **list = nullptr;
    StringListInit(&list);
    StringListRemove(list, "odd");

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[1]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[2]) == list);

    StringListDestroy(&list);
}

TEST(list_remove, single_element_list_remove_not_present) {
    char **list = nullptr;
    StringListInit(&list);
    StringListAdd(list, "odd");
    StringListRemove(list, "od");

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
    StringListAdd(list, "odd");
    StringListRemove(list, "odd");

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
    StringListAdd(list, "odd");
    StringListAdd(list, "add");
    StringListAdd(list, "sub");
    StringListAdd(list, "");
    StringListAdd(list, "dodd");

    StringListRemove(list, "dd");

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
    StringListAdd(list, "dd");
    StringListAdd(list, "odd");
    StringListAdd(list, "add");
    StringListAdd(list, "sub");
    StringListAdd(list, "dd");
    StringListAdd(list, "");
    StringListAdd(list, "dodd");

    StringListRemove(list, "dd");

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
    StringListAdd(list, "dd");
    StringListAdd(list, "odd");
    StringListAdd(list, "add");
    StringListAdd(list, "sub");
    StringListAdd(list, "dd");
    StringListAdd(list, "");
    StringListAdd(list, "dodd");

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
    StringListAdd(list, "b");
    char value[] = "a";
    int index = StringListIndexOf(list, value);

    ASSERT_EQ(index, -1);

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
    StringListAdd(list, "a");
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
    StringListAdd(list, "a");
    StringListAdd(list, "b");
    StringListAdd(list, "c");
    StringListAdd(list, "d");
    StringListAdd(list, "");
    StringListAdd(list, "e");
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
    StringListAdd(list, "a");
    StringListAdd(list, "b");
    StringListAdd(list, "c");
    StringListAdd(list, "d");
    StringListAdd(list, "");
    StringListAdd(list, "e");
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
