#include <iostream>
using namespace std;

// Node structure to represent each element in the stack
struct Node {
    int data;
    Node* link;
};

// LinkedStack class to implement a stack using a linked list
class LinkedStack {
private:
    Node* top;      // Pointer to the top node in the stack
    int count;      // Counter to track the number of elements in the stack

public:
    // Constructor
    LinkedStack();

    // Destructor
    ~LinkedStack();

    // Stack operations
    bool isEmpty() const;
    void push(int data);
    void pop();
    int getTop() const;
    void traverse() const;
    void destroy();
    int length() const;
};

// Constructor: Initialize an empty stack
LinkedStack::LinkedStack() {
    top = nullptr;
    count = 0;
}

// Destructor: Destroy the stack
LinkedStack::~LinkedStack() {
    destroy();
}

// Check if the stack is empty
bool LinkedStack::isEmpty() const {
    return top == nullptr;
}

// Push an element onto the stack
void LinkedStack::push(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = top;
    top = newNode;

    count++; // Increment count to reflect the new element
    cout << data << " is successfully inserted into the stack." << endl;
}

// Pop the top element from the stack
void LinkedStack::pop() {
    if (isEmpty()) {
        cout << "Cannot pop from an empty stack." << endl;
        return;
    }

    Node* curNode = top; // Store the current top node
    top = top->link;     // Update the top pointer to the next node

    cout << curNode->data << " is popped out successfully from the stack." << endl;

    delete curNode; // Free the memory allocated to the node
    count--;        // Decrement count to reflect the removed element
}

// Get the top element of the stack
int LinkedStack::getTop() const {
    if (isEmpty()) {
        cout << "Cannot getTop from an empty stack." << endl;
        return -1; // Return a placeholder value
    }
    return top->data;
}

// Traverse and display the stack's contents
void LinkedStack::traverse() const {
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    Node* curNode = top;
    cout << "Stack contents: ";
    while (curNode != nullptr) {
        cout << curNode->data << " ";
        curNode = curNode->link;
    }
    cout << endl;
}

// Destroy the stack and free memory
void LinkedStack::destroy() {
    Node* curNode;
    while (top != nullptr) {
        curNode = top;
        top = top->link;
        delete curNode;
    }
    top = nullptr;
    count = 0; // Reset the count
}

// Get the length of the stack
int LinkedStack::length() const {
    return count;
}

// Main function to test the LinkedStack class
int main() {
    LinkedStack myLinkedStack;
    int choice = 0;
    int data;

    cout << "Welcome to the Stack Management System!\n";
    cout << "=======================================\n";

    while (choice != 7) {
        // Display menu
        cout << "\nChoice Menu:\n";
        cout << "1: Push to the stack\n";
        cout << "2: Pop from the stack\n";
        cout << "3: Get top from the stack\n";
        cout << "4: Destroy the stack\n";
        cout << "5: Traverse the stack\n";
        cout << "6: Length of the stack\n";
        cout << "7: Exit\n";
        cout << "---------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1:
                cout << "Enter the data to push: ";
                cin >> data;
                myLinkedStack.push(data);
                break;

            case 2:
                myLinkedStack.pop();
                break;

            case 3:
                cout << "[Top Element]: " << myLinkedStack.getTop() << "\n";
                break;

            case 4:
                myLinkedStack.destroy();
                cout << "Stack destroyed successfully!" << endl;
                break;

            case 5:
                myLinkedStack.traverse();
                break;

            case 6:
                cout << "[Stack Length]: " << myLinkedStack.length() << "\n";
                break;

            case 7:
                cout << "Thank you for using the Stack Management System. Goodbye!\n";
                break;

            default:
                cout << "[Error] Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
