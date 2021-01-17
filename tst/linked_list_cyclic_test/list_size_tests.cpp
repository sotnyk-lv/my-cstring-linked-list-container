#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

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
    StringListAdd(list, (char*)"super_new_string");
    ASSERT_EQ(StringListSize(list), 3);

    StringListDestroy(&list);
}

TEST(list_size, empty_list_size) {
    char **list = nullptr;
    StringListInit(&list);

    ASSERT_EQ(StringListSize(list), 0);

    StringListDestroy(&list);
}