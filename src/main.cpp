#include <iostream>

#include "linked_cyclic_list/my_linked_cyclic_list.h"

int main() {

    char **list = nullptr;
    StringListInit(&list);

    StringListAdd(list, (char*)"word");
    StringPrint(list);
    std::cout << StringListIndexOf(list, (char*)"q") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;


    StringListAdd(list, (char*)"second_word");
    StringListAdd(list, (char*)"3word");
    StringListAdd(list, (char*)"4");
    StringListAdd(list, (char*)"five");
    StringPrint(list);
    std::cout << StringListIndexOf(list, (char*)"3word") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListRemove(list, (char*)"4");
    StringPrint(list);
    std::cout << StringListIndexOf(list, (char*)"4") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListRemove(list, (char*)"100");
    StringPrint(list);
    std::cout << StringListIndexOf(list, (char*)"100") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListAdd(list, (char*)"five");
    StringListAdd(list, (char*)"word");
    StringListAdd(list, (char*)"word");
    StringListAdd(list, (char*)"five");
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListReplaceInStrings(list, (char*)"word", (char*)"new_word");
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListRemoveDuplicates(list);
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    SwapNodes(reinterpret_cast<char **>(list[1]), reinterpret_cast<char **>(list[2]));
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListSort(list);
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    char** test_list;
    StringListToString(list, &test_list);
    for (int i=0; i<StringListSize(list); ++i) {
        std::cout << i << " " << test_list[i] << std::endl;
        free(test_list[i]);
        test_list[i] = nullptr;
    }
    free(test_list);
    test_list = nullptr;

    StringListDestroy(&list);

    return 0;
}
