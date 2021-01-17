#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

TEST(list_creation, nullptr_list_creation) {
    char ***list = nullptr;
    StringListInit(list);

    ASSERT_TRUE(list == nullptr);
}

TEST(list_creation, empty_list_creation) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_TRUE(list != nullptr);
    ASSERT_TRUE(list[WORD] == nullptr);
    ASSERT_TRUE(reinterpret_cast<char **>(list[NEXT_NODE]) == list);
    ASSERT_TRUE(reinterpret_cast<char **>(list[PREV_NODE]) == list);

    StringListDestroy(&list);
}