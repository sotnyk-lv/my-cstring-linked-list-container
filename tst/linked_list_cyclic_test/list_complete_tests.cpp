#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "linked_cyclic_list/my_linked_cyclic_list.h"

#define WORD 0
#define NEXT_NODE 1
#define PREV_NODE 2

#include "test_helper.h"

TEST(list_complete_test, complete_test_1) {
    testing::internal::CaptureStdout();

    char **list = nullptr;
    StringListInit(&list);
    std::vector<std::string> words = {"a", "h", "", " ", "c", "b", "a", "d"};
    ASSERT_EQ(StringListSize(list), 0);
    for (auto & word: words) {
        StringListAdd(list, word);
    }
    ASSERT_EQ(StringListSize(list), 8);

    StringPrint(list);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, (char*)"a\nh\n\n \nc\nb\na\nd\n");

    StringListRemove(list, (char*)"");

    words.erase(std::find(words.begin(),words.end(),""));
    char** arr;
    StringListToString(list, &arr);
    ASSERT_EQ(StringListSize(list), 7);
    ASSERT_TRUE(arr != nullptr);
    int i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }
    free_string_array(arr, StringListSize(list));

    ASSERT_EQ(StringListIndexOf(list, (char*)" "), 2);
    ASSERT_EQ(StringListIndexOf(list, (char*)"a"), 0);
    ASSERT_NE(StringListIndexOf(list, (char*)" "), 5);
    ASSERT_EQ(StringListIndexOf(list, (char*)"d"), 6);

    StringListRemoveDuplicates(list);
    words = {"a", "h", " ", "c", "b", "d"};
    StringListToString(list, &arr);
    ASSERT_EQ(StringListSize(list), 6);
    ASSERT_TRUE(arr != nullptr);
    i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }

    free_string_array(arr, StringListSize(list));

    StringListReplaceInStrings(list, (char*)"a", (char*)"aa");
    words = {"aa", "h", " ", "c", "b", "d"};
    StringListToString(list, &arr);
    ASSERT_EQ(StringListSize(list), 6);
    ASSERT_TRUE(arr != nullptr);
    i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }
    free_string_array(arr, StringListSize(list));

    StringListSort(list);
    std::sort(words.begin(), words.end());
    StringListToString(list, &arr);
    ASSERT_EQ(StringListSize(list), 6);
    ASSERT_TRUE(arr != nullptr);
    i=0;
    for (auto & word: words) {
        ASSERT_STREQ(arr[i], word.c_str());
        ++i;
    }
    free_string_array(arr, StringListSize(list));

    StringListDestroy(&list);
}