#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node *next;
    Node *prev;
};
class DLL
{
    private:
    Node *head;
    Node *tail;
    int count;

    public:
    DLL();
    ~DLL();
    bool isEmpty() const;
    void insert(int data, int position);
    void traverse() const; // Declare
    void remove(int data); // Declare
    void destroy();
    bool search(int data); // Declare
    int length(); // Declare
};

DLL::DLL(){
        head = nullptr;
        tail = nullptr;
        count = 0;
}
DLL::~DLL(){
    destroy();
}
bool DLL::isEmpty() const
{
 return head == nullptr;
}
void DLL::insert(int data, int position)
{
Node *newNode = new Node;
newNode->data = data;
newNode->next = nullptr;
newNode->prev = nullptr;


    if(position==0)
{
        newNode->next = head;
        newNode->prev = nullptr;
        if(head!=nullptr)
        {
            head->prev = newNode;
        }
        else 
        {
            tail=newNode;
            
        }
        head=newNode;
        cout<<data<<" is inserted successfully to the list.";
        count++;
}
else 
{
    int countNode = 1;
    Node *curNode=head;
  
    while(curNode&&countNode<position)
    {   
        curNode=curNode->next;
        countNode++;

    }
    if(curNode)
    {
        newNode->next=curNode->next;
        
        newNode->prev=curNode;
        if(curNode->next!=nullptr)
        {
            (curNode->next)->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        curNode->next=newNode;
        cout<<data<<" is inserted to the list.";
        count++;

    }
   else  
    {
       newNode->next = nullptr;
       newNode->prev = tail;
       tail -> next = newNode;
        tail = newNode;
        cout<<data<<" is inserted in to the list";
        count++;
    }
}
}

void DLL::traverse()const
{
    if(!isEmpty())
    {
        Node *curNode = head;
        cout<<"Items in forward direction ";
        while(curNode!=nullptr)
        {
            cout<<curNode->data<<"  ";
            curNode=curNode->next;
        }
        cout<<endl;
        cout<<" Items in backward direction ";
        curNode=tail;
        while(curNode!=nullptr)
        {
            cout<<curNode->data<<" ";
            curNode=curNode->prev;
        }

    }
    else 
    {
        cout<<"The list is empty";
    }

}
void DLL::remove(int data)
{
        if(!isEmpty())
        {
                Node* curNode=head;
                while(curNode&&curNode->data!=data)
                {
                    curNode=curNode->next;
                }
                if(curNode!=nullptr)
                {
                    if(curNode==head)
                    {
                        head=head->next;
                        if(head!=nullptr)
                        {
                            head->prev = nullptr;
                        }
                        else 
                    {
                        tail =nullptr;
                    }
                    }
                    else 
                    {
                        curNode->prev->next=curNode->next;
                        if(curNode->next!=nullptr)
                        {
                            curNode->next->prev=curNode->prev;
                        }
                        else 
                        {
                            tail = curNode->prev;
                        }
                    }
                    
                        cout<<data<<" is removed successfully from the list.";
                        delete curNode;
                        count--;


                }
                else 
                {
                    cout<<data<<" is not found in the list.";
                }


        }
        else 
        {
            cout<<"The list is empty.";
        }

}
void DLL::destroy()
{
Node *temp;
while(head!=nullptr)
{
    temp =head;
    head = head->next;
    delete temp;
}
tail = nullptr;
count = 0;
}
bool DLL ::search(int data)
{
    Node *curNode = head;
    while (curNode)
    {
        if (curNode->data == data)
            return true; // Return true if data is found
        curNode = curNode->next; // Move to the next node
    }
    return false; // Return false if data is not found
}
int DLL ::length()
{
    return count; // Return the count of nodes
}
int main() {
    DLL myList; // Create a List object
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