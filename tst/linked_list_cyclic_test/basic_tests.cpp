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

    EXPECT_TRUE(arr != nullptr);
    EXPECT_STREQ(arr[WORD], element);

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
    StringListAdd(list, "third_string");
    StringPrint(list);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "first_string\nsecond_string\nthird_string\n");

    StringListDestroy(&list);
}
