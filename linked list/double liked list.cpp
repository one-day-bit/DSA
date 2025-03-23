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
        cout<<data<<" is inserted to the list.";
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
            cout<<curNode->data<<" ";
            curNode=curNode->next;
        }
        cout<<" Items in backward direction ";
        curNode=tail;
        while(curNode!=nullptr)
        {
            cout<<curNode->data;
            curNode=curNode->prev;
        }

    }
    else 
    {
        cout<<"The list is empty";
    }

}