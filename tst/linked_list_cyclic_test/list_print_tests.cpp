#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

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
    StringListAdd(list, (char*)"first_string");
    StringListAdd(list, (char*)"second_string");
    StringListAdd(list, (char*)"");
    StringListAdd(list, (char*)"fourth_string");
    StringPrint(list);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "first_string\nsecond_string\n\nfourth_string\n");

    StringListDestroy(&list);
}