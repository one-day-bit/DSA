#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

class List {
private:
    Node *head;
    int count;

public:
    List();
    ~List();
    bool isEmpty() const;
    void insert(int data, int position);
    void traverse() const; // Declare
    void remove(int data); // Declare
    void destroy();
    bool search(int data); // Declare
    int length(); // Declare
};

List::List() {
    head = nullptr;
    count = 0;
}

List::~List() {
    destroy();
}

bool List::isEmpty() const {
    return head == nullptr;
}

void List::insert(int data, int position) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->link = nullptr;

    if (position == 0) {
        newNode->link = head;
        head = newNode;
        cout << data << " is inserted successfully\n";
        count++;
    } else {
        int countNode = 1;
        Node *curNode = head;
        while (curNode && countNode < position) {
            curNode = curNode->link;
            countNode++;
        }
        if (curNode) {
            newNode->link = curNode->link;
            curNode->link = newNode;
            cout << data << " is inserted successfully\n";
            count++;
        } else {
            cout << data << " is not inserted in the given position\n";
            delete newNode;
        }
    }
}
void List::traverse()const
{
 Node *curNode = head;
 while(curNode!=nullptr)
 {
    cout<<curNode->data<<"  ";
    curNode=curNode->link;
 }
 cout<<"\n";
}

void List::remove(int data)
{
    if(!isEmpty())
    {
        Node *curNode= head;
        Node *prev = nullptr;
        while(curNode && curNode->data!=data)
        {
            prev = curNode;
            curNode = curNode->link;
        }
        if(curNode)
        {
            if (head == curNode) {
                head = head->link;
            } else {
                prev->link = curNode->link;
            }
            cout << curNode->data << " is deleted.\n";
            delete curNode;
            count--;
        }
        else 
        {
            cout <<data<< " is not found in the list!";
        }
    }
    else 
    {
        cout<<"The list is empty!";
    }

}

void List::destroy()
{
Node *temp;
while(head!=nullptr)
{
    temp =head;
    head = head->link;
    delete temp;
}
count = 0;
}

bool List ::search(int data)
{
    Node *curNode = head;
    while (curNode)
    {
        if (curNode->data == data)
            return true; // Return true if data is found
        curNode = curNode->link; // Move to the next node
    }
    return false; // Return false if data is not found
}

int List ::length()
{
    return count; // Return the count of nodes
}

int main() {
    List myList; // Create a List object
    int choice = 0; // User's menu choice
    int data, position; // Data and position for operations

    while (choice != 7) { // Continue until the user chooses to exit (choice == 7)
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Insert data\n";
        cout << "2. Traverse list\n";
        cout << "3. Remove data\n";
        cout << "4. Search data\n";
        cout << "5. Get length\n";
        cout << "6. Destroy list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Use switch-case to handle the user's choice
        switch (choice) {
            case 1: // Insert data
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert (0 for head): ";
                cin >> position;
                myList.insert(data, position);
                break;

            case 2: // Traverse list
                cout << "List contents: ";
                myList.traverse();
                break;

            case 3: // Remove data
                cout << "Enter data to remove: ";
                cin >> data;
                myList.remove(data);
                break;

            case 4: // Search data
                cout << "Enter data to search: ";
                cin >> data;
                if (myList.search(data)) {
                    cout << data << " is found in the list.\n";
                } else {
                    cout << data << " is not found in the list.\n";
                }
                break;

            case 5: // List length
                cout << "The list contains " << myList.length() << " nodes.\n";
                break;

            case 6: // Destroy list
                myList.destroy();
                cout << "The list has been destroyed.\n";
                break;

            case 7: // Exit
                cout << "Exiting program. Goodbye!\n";
                break;

            default: // Invalid input
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0; // Indicate successful program termination
}
