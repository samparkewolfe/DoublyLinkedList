//
//  DoublyLinkedList.hpp
//  DoubleLinkedList
//
//  Created by Samuel Parke-Wolfe on 27/03/2024.
//

#pragma once

template <typename ListType>
class DoublyLinkedList {
    struct Node {
        ListType value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
    };
    
    struct Iterator {
        std::shared_ptr<Node> node;
        
        bool operator!= (const Iterator& other) {
            return node != other.node;
        }
        
        void operator++ () {
            node = node->next;
        }
        
        int operator*() {
            return node->value;
        }
    };
    
public:
    Iterator begin() {
        return Iterator{front};
    }
    
    Iterator end() {
        return Iterator{back->next};
    }
    
    void pushBack(const ListType& value) {
        auto newNode = std::make_shared<Node>();
        newNode->value = value;
        
        unsigned int size = this->size();
        
        if (size == 0) {
            back = newNode;
            front = newNode;
        } else if (size == 1) {
            back = newNode;
            front->next = back;
            back->prev = front;
        } else if (size > 1) {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
    }
    
    void pushFront(const ListType& value) {
        auto newNode = std::make_shared<Node>();
        newNode->value = value;
        
        unsigned int size = this->size();
        
        if (size == 0) {
            back = newNode;
            front = newNode;
        } else if (size == 1) {
            front = newNode;
            front->next = back;
            back->prev = front;
        } else if (size > 1) {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
    
    void insert(const unsigned int index, const ListType& value) {
        auto newNode = std::make_shared<Node>();
        newNode->value = value;
        
        unsigned int size = this->size();
        
        if ((size == 0 && index == 0) || (size == 1 && index == 0)) {
            pushFront(value);
            return;
        }
        
        if (index >= size) {
            throw std::out_of_range("");
        }
        
        auto node = front;
        unsigned int nodeIndex = 0;
        bool endLoopEarly = false;
        
        while (node != nullptr && !endLoopEarly) {
            
            if (nodeIndex == index) {
                node->prev->next = newNode;
                newNode->prev = node->prev;
                
                node->prev = newNode;
                newNode->next = node;
                
                endLoopEarly = true;
            }
            
            nodeIndex++;
            node = node->next;
        }
    }
    
    void popBack() {
        const unsigned int size = this->size();
        
        if (size == 0) {
            throw std::out_of_range("");
        } else if (size == 1) {
            front = nullptr;
            back = nullptr;
        } else if (size == 2) {
            back = nullptr;
            front->next = nullptr;
            back = front;
        } else if (size > 2) {
            back = back->prev;
            back->next = nullptr;
        }
    }
    
    void popFront() {
        const unsigned int size = this->size();
        
        if (size == 0) {
            throw std::out_of_range("");
        } else if (size == 1) {
            front = nullptr;
            back = nullptr;
        } else if (size == 2) {
            front = nullptr;
            back->prev = nullptr;
            front = back;
        } else if (size > 2) {
            front = front->next;
            front->prev = nullptr;
        }
    }
    
    void remove(const unsigned int index) {
        const unsigned int size = this->size();
        
        if (size == 0 || index >= size) {
            throw std::out_of_range("");
        } else if (size == 1) {
            front = nullptr;
            back = nullptr;
            return;
        } else if (size == 2) {
            if (index == 0) {
                front = back;
            } else {
                back = front;
            }
            
            front->prev = nullptr;
            front->next = nullptr;
            return;
        }
        
        if (index == 0) {
            front = front->next;
            front->prev = nullptr;
            return;
        } if (index == size - 1) {
            back = back->prev;
            back->next = nullptr;
            return;
        }
        
        auto node = front;
        int nodeIndex = 0;
        bool endLoopEarly = false;
        while (node != nullptr) {
            if (nodeIndex == index && !endLoopEarly) {
                
                auto previousNode = node->prev;
                auto nextNode = node->next;
                
                previousNode->next = nextNode;
                nextNode->prev = previousNode;
                
                endLoopEarly = true;
            }
            
            node = node->next;
            nodeIndex++;
        }
    }
    
    const unsigned int size() {
        if (front == nullptr && back == nullptr) {
            return 0;
        } else if (front == back) {
            return 1;
        } else {
            unsigned int count = 0;
            std::shared_ptr<Node> node = front;
            while (node != nullptr) {
                node = node->next;
                count++;
            }
            return count;
        }
    }

    std::shared_ptr<Node> front;
    std::shared_ptr<Node> back;
};
