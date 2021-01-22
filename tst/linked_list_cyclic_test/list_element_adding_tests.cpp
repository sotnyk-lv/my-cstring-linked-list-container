#include <string>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

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