#include <iostream>

// Node structure representing a node in the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};
void chk (Node *&HEAD);
int main() {
    // Initializing an empty linked list
    Node* HEAD = nullptr;
    chk (HEAD);
    //
    // Remember to free the allocated memory (not shown in this simple example)
    
    return 0;
}


void chk (Node *&HEAD)
{
   //  Checking if the linked list is empty
    if (HEAD == NULL) {
        std::cout << "1. Linked list is empty." << std::endl;
    } else {
        std::cout << "Linked list is not empty." << std::endl;
    }

    // Adding a node to the linked list
    HEAD = new Node(42);

    // Checking if the linked list is empty after adding a node
    if (HEAD == NULL) {
        std::cout << "Linked list is empty." << std::endl;
    } else {
        std::cout << "2. Linked list is not empty." << std::endl;
    }
}
