//
//  main.cpp
//  DoubleLinkedList
//
//  Created by Samuel Parke-Wolfe on 27/03/2024.
//

#include <iostream>

#include "DoublyLinkedList.hpp"
#include "DoublyLinkedListTests.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<std::string> failedTests;
    
    for (auto& [title, test] : DoublyLinkedListTests::tests) {
        if (test()) {
            std::cout << "PASSED: ";
        } else {
            std::cout << "FAILED: ";
            failedTests.push_back(title);
        }
        
        std::cout << title << std::endl;
    }
    
    if (failedTests.empty()) {
        std::cout << "All Tests Passed!" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Failed Tests:" << std::endl;
        for (const auto& testName : failedTests) {
            std::cout << testName << std::endl;
        }
    }
    
    return 0;
}
