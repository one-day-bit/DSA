#include <iostream>
using namespace std;

class StackArray {
    private:
        int MaxSize;
        int top;
        int stack[100];

    public:
        StackArray() {
            top = -1;
            MaxSize = 100;
        }

        bool isEmpty() const {
            return top == -1;
        }

        bool isFull() const {
            return top == MaxSize - 1;
        }

        void push(int data);
        void pop();
        int getTop() const;
        void destroy();
        void traverse() const;
        int length() const {
            return top + 1;
        }
};

// Push an element onto the stack
void StackArray::push(int data) {
    if (isFull()) {
        cout << "[Error] The stack is full. Adding more elements will cause stack overflow.\n";
        return;
    }
    stack[++top] = data;
    cout << "[Success] " << data << " has been pushed to the stack.\n";
}

// Pop the top element from the stack
void StackArray::pop() {
    if (isEmpty()) {
        cout << "[Error] There is nothing in the stack to pop.\n";
        return;
    }
    cout << "[Success] Popped element: " << stack[top--] << "\n";
}

// Get the top element of the stack
int StackArray::getTop() const {
    if (isEmpty()) {
        cout << "[Error] There is no element in the stack.\n";
        return -1;
    }
    return stack[top];
}

// Destroy the stack
void StackArray::destroy() {
    top = -1;
    cout << "[Success] The stack has been cleared.\n";
}

// Traverse and display the stack
void StackArray::traverse() const {
    if (isEmpty()) {
        cout << "[Info] The stack is empty.\n";
        return;
    }
    cout << "[Stack Contents]: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    StackArray myArray;
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
                myArray.push(data);
                break;

            case 2:
                myArray.pop();
                break;

            case 3:
                cout << "[Top Element]: " << myArray.getTop() << "\n";
                break;

            case 4:
                myArray.destroy();
                break;

            case 5:
                myArray.traverse();
                break;

            case 6:
                cout << "[Stack Length]: " << myArray.length() << "\n";
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
