#include <iostream>

//#include "MyLinkedList.h"
#include "linked_cyclic_list/my_linked_cyclic_list.h"

int main() {

    char **list = nullptr;
    StringListInit(&list);
//    StringListInit(&list, "wabc");

    StringListAdd(list, "word");
    StringPrint(list);
    std::cout << StringListIndexOf(list, "q") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;


    StringListAdd(list, "secondword");
    StringListAdd(list, "3word");
    StringListAdd(list, "4");
    StringListAdd(list, "five");
    StringPrint(list);
    std::cout << StringListIndexOf(list, "3word") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListRemove(list, "4");
    StringPrint(list);
    std::cout << StringListIndexOf(list, "4") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListRemove(list, "100");
    StringPrint(list);
    std::cout << StringListIndexOf(list, "100") << std::endl;
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListAdd(list, "five");
    StringListAdd(list, "word");
    StringListAdd(list, "word");
    StringListAdd(list, "five");
    StringPrint(list);
    std::cout << StringListSize(list) << "\n" << std::endl;

    StringListReplaceInStrings(list, "word", "new_word");
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

    StringListDestroy(&list);

    return 0;
}
