//
//  DoublyLinkedListTests.hpp
//  DoublyLinkedList
//
//  Created by Samuel Parke-Wolfe on 29/03/2024.
//

#pragma once

#define TEST_CASES_BEGIN(name)                                                  \
struct name {                                                                   \
    static std::vector<std::pair<std::string, std::function<bool()>>> tests;    \
};                                                                              \
std::vector<std::pair<std::string, std::function<bool()>>> name::tests = {      \

#define TEST_CASES_END };

#define TEST_CASE(title, test) \
{ title, []() -> bool test }, \


TEST_CASES_BEGIN(DoublyLinkedListTests)

TEST_CASE("doesSizeFunctionWork", {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    return list.size() == 6;
})

TEST_CASE("canPushBackOneNode", {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    
    return list.size() == 1 &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.front->value == 0 &&
            list.back == list.front;
})

TEST_CASE("canPushBackTwoNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    
    return list.size() == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.front->value == 0 &&
            list.back->prev == list.front &&
            list.back->next == nullptr &&
            list.back->value == 1;
})

TEST_CASE("canPushBackThreeNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    return list.size() == 3 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.back->prev->value == 1 &&
            list.back->next == nullptr &&
            list.back->value == 2;
})

TEST_CASE("canPushFrontOneNode", {
    DoublyLinkedList<int> list;
    list.pushFront(0);
    
    return list.size() == 1 &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.front->value == 0 &&
            list.back == list.front;
})

TEST_CASE("canPushFrontTwoNodes",  {
    DoublyLinkedList<int> list;
    list.pushFront(1);
    list.pushFront(0);
    
    return list.size() == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.front->value == 0 &&
            list.back->prev == list.front &&
            list.back->next == nullptr &&
            list.back->value == 1;
})

TEST_CASE("canPushFrontThreeNodes",  {
    DoublyLinkedList<int> list;
    list.pushFront(2);
    list.pushFront(1);
    list.pushFront(0);
    
    return list.size() == 3 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.back->prev->value == 1 &&
            list.back->next == nullptr &&
            list.back->value == 2;
})

TEST_CASE("canForwardIterateManually",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    
    int nodeIndex = 0;
    auto node = list.front;
    
    while (node != nullptr) {
        if (node->value != nodeIndex) {
            return false;
        }
        node = node->next;
        nodeIndex++;
    }
    return true;
})

TEST_CASE("canBackwardsIterateManually",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    
    int nodeIndex = 5;
    auto node = list.back;
    
    while (node != nullptr) {
        if (node->value != nodeIndex) {
            return false;
        }
        node = node->prev;
        nodeIndex--;
    }
    return true;
})

TEST_CASE("canRangeBasedForwardInterateWithSizeOfOne",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    
    int nodeIndex = 0;
    for (auto element : list) {
        if (element != nodeIndex) {
            return false;
        }
        nodeIndex++;
    }
    return true;
})

TEST_CASE("canRangeBasedForwardInterateWithSizeOfTwo",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    
    int nodeIndex = 0;
    for (auto element : list) {
        if (element != nodeIndex) {
            return false;
        }
        nodeIndex++;
    }
    return true;
})

TEST_CASE("canRangeBasedForwardInterate",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    
    int nodeIndex = 0;
    for (auto element : list) {
        if (element != nodeIndex) {
            return false;
        }
        nodeIndex++;
    }
    return true;
})

TEST_CASE("doesFailForPoppingBackOfEmptyList",  {
    DoublyLinkedList<int> list;
    
    try {
        list.popBack();
    } catch (std::out_of_range exeption) {
        return true;
    }
    return false;
})

TEST_CASE("canPopBackAfterAddingOneNode",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.popBack();
    
    return list.size() == 0 &&
            list.front == nullptr &&
            list.back == nullptr;
})

TEST_CASE("canPopBackAfterAddingTwoNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.popBack();
    
    return list.size() == 1 &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.front->value == 0 &&
            list.back == list.front;
})

TEST_CASE("canPopBackAfterAddingThreeNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.popBack();
    
    return list.size() == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.front->value == 0 &&
            list.back->prev == list.front &&
            list.back->next == nullptr &&
            list.back->value == 1;
})

TEST_CASE("canPopBackAfterAddingFourNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popBack();
    
    return list.size() == 3 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.back->prev->value == 1 &&
            list.back->next == nullptr &&
            list.back->value == 2;
})

TEST_CASE("doesFailForPoppingFrontOfEmptyList",  {
    DoublyLinkedList<int> list;
    
    try {
        list.popFront();
    } catch (std::out_of_range exeption) {
        return true;
    }
    return false;
})

TEST_CASE("canPopFrontAfterAddingOneNode",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.popFront();
    
    return list.size() == 0 &&
            list.front == nullptr &&
            list.back == nullptr;
})

TEST_CASE("canPopFrontAfterAddingTwoNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.popFront();
    
    return list.size() == 1 &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.front->value == 1 &&
            list.back == list.front;
})

TEST_CASE("canPopFrontAfterAddingThreeNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.popFront();
    
    return list.size() == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.front->value == 1 &&
            list.back->prev == list.front &&
            list.back->next == nullptr &&
            list.back->value == 2;
})

TEST_CASE("canPopFrontAfterAddingFourNodes",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popFront();
    
    return list.size() == 3 &&
            list.front->prev == nullptr &&
            list.front->value == 1 &&
            list.front->next->value == 2 &&
            list.back->prev->value == 2 &&
            list.back->next == nullptr &&
            list.back->value == 3;
})

TEST_CASE("doesNotAllowInsertToOutOfBoundsIndex",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    try {
        list.insert(3, 3);
    } catch (std::out_of_range exeption) {
        return true;
    }
    return false;
})

TEST_CASE("canInsertToEmptyList",  {
    DoublyLinkedList<int> list;
    list.insert(0, 0);
    
    return list.size() == 1 &&
            list.front->value == 0 &&
            list.back->value == 0 &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.back->prev == nullptr &&
            list.back->next == nullptr &&
            list.front == list.back;
})

TEST_CASE("canInsertElementToListOfOneElement",  {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.insert(0, 0);
    
    return list.size() == 2 &&
            list.front->value == 0 &&
            list.back->value == 1 &&
            list.front->prev == nullptr &&
            list.front->next->value == 1 &&
            list.back->prev->value == 0 &&
            list.back->next == nullptr;
})

TEST_CASE("canInsertElementToListOfTwoElements",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(2);
    list.insert(1, 1);
    
    return list.size() == 3 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.back->prev->value == 1 &&
            list.back->value == 2 &&
            list.back->next == nullptr;
})

TEST_CASE("canInsertElementToListOfThreeElements",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(3);
    list.insert(2, 2);
    
    return list.size() == 4 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.back->prev->value == 2 &&
            list.back->value == 3 &&
            list.back->next == nullptr;
})

TEST_CASE("canInsertElementToListOfFourElements",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(3);
    list.pushBack(4);
    list.insert(2, 2);
    
    return list.size() == 5 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.front->next->next->value == 2 &&
            list.front->next->next->next->value == 3 &&
            list.front->next->next->next->next->value == 4 &&
            list.back->prev->prev->prev->prev->value == 0 &&
            list.back->prev->prev->prev->value == 1 &&
            list.back->prev->prev->value == 2 &&
            list.back->prev->value == 3 &&
            list.back->value == 4 &&
            list.back->next == nullptr;
})

TEST_CASE("doesNotAllowRemovalFromEmptyList",  {
    DoublyLinkedList<int> list;
    
    try {
        list.remove(0);
    } catch (std::out_of_range exeption) {
        return true;
    }
    return false;
})

TEST_CASE("doesNotAllowRemovalOfOutOfRangeIndex",  {
    DoublyLinkedList<int> list;
    
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    try {
        list.remove(3);
    } catch (std::out_of_range exeption) {
        return true;
    }
    return false;
})

TEST_CASE("canRemoveFromListOfSizeOne",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    
    list.remove(0);
    
    return list.size() == 0 &&
            list.front == nullptr &&
            list.back == nullptr;
})

TEST_CASE("canRemoveFirstElementFromListOfSizeTwo",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    
    list.remove(0);
    
    return list.size() == 1 &&
            list.front->value == 1 &&
            list.front == list.back &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.back->prev == nullptr &&
            list.back->next == nullptr;
})

TEST_CASE("canRemoveSecondElementFromListOfSizeTwo",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    
    list.remove(1);
    
    return list.size() == 1 &&
            list.front->value == 0 &&
            list.front == list.back &&
            list.front->prev == nullptr &&
            list.front->next == nullptr &&
            list.back->prev == nullptr &&
            list.back->next == nullptr;
})

TEST_CASE("canRemoveFirstElementFromListOfSizeThree",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    list.remove(0);
    
    return list.size() == 2 &&
            list.front->value == 1 &&
            list.back->value == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.back->prev == list.front &&
            list.back->next == nullptr;
            
})

TEST_CASE("canRemoveSecondElementFromListOfSizeThree",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    list.remove(1);
    
    return list.size() == 2 &&
            list.front->value == 0 &&
            list.back->value == 2 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.back->prev == list.front &&
            list.back->next == nullptr;
})

TEST_CASE("canRemoveThirdElementFromListOfSizeThree",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    
    list.remove(2);
    
    return list.size() == 2 &&
            list.front->value == 0 &&
            list.back->value == 1 &&
            list.front->prev == nullptr &&
            list.front->next == list.back &&
            list.back->prev == list.front &&
            list.back->next == nullptr;
})

TEST_CASE("canRemoveElementFromListOfSizeFive",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    
    list.remove(2);
    
    return list.size() == 4 &&
            list.front->prev == nullptr &&
            list.front->value == 0 &&
            list.front->next->value == 1 &&
            list.front->next->next->value == 3 &&
            list.front->next->next->next->value == 4 &&
            list.back->prev->prev->prev->value == 0 &&
            list.back->prev->prev->value == 1 &&
            list.back->prev->value == 3 &&
            list.back->value == 4 &&
            list.back->next == nullptr;
})

TEST_CASE("canAddAndRemoveFiveElements",  {
    DoublyLinkedList<int> list;
    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    
    list.remove(0);
    list.remove(0);
    list.remove(0);
    list.remove(0);
    list.remove(0);
    
    return list.size() == 0 &&
            list.front == nullptr &&
            list.back == nullptr;
})

TEST_CASE("doesWorkWithStrings",  {
    DoublyLinkedList<std::string> list;
    list.pushBack("Anna");
    list.pushBack("Amy");
    list.pushBack("Rebecca");
    
    return list.size() == 3;
})

TEST_CASES_END
