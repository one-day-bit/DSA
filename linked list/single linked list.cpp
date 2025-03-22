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
        cout << data << " The data is inserted successfully\n";
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
            cout << data << " The data is inserted successfully\n";
            count++;
        } else {
            cout << data << " The data is not inserted in the given position\n";
            delete newNode;
        }
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

void List::traverse()const
{
 Node *curNode = head;
 while(head!=nullptr)
 {
    cout<<curNode->data<<"  ";
    curNode=head->link;
 }
 cout<<"\n";
}

void List::remove(int data)
{
    if(isEmpty())
    {
        Node *curNode= head;
        Node *prev = nullptr;
        while(curNode &&& curNode->data !=data)
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
            cout << "List is empty!\n";
        }
    }

}