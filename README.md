# CDS-doubly-and-circular-linked-list-

AIM:- to implement doubly and circular linked list<br>

Software used:-VS code <br>

Theory:-<br>
Doubly linked list:-A doubly linked list is a type of linked list where each node contains three components: data, a pointer to the next node, and a pointer to the previous node. Unlike a singly linked list, where traversal is only possible in one direction, a doubly linked list allows traversal in both directions—forward and backward. This is achieved by maintaining two pointers: one to the next node and one to the previous node.<br>

Circular linked lis:-A circular linked list is a type of linked list where the last node points back to the first node, forming a circular structure. This allows traversal to loop back to the beginning, either continuously or after a complete cycle. Circular linked lists can be either singly linked (where each node has one pointer to the next node) or doubly linked (where each node also has a pointer to the previous node).<br>

CODE:-
1).doubly linked list<br>

~~~
#include <iostream>
using namespace std;

struct node 
{
    int data;        
    node* next;      
    node* prev;      
};

node* createnode(int value) 
{
    node* newnode = new node();  
    newnode->data = value;       
    newnode->next = nullptr;    
    newnode->prev = nullptr;   
    return newnode;
}


void insertdata(node*& head, int value) 
{

    node* newnode = createnode(value);
    if (head == nullptr) 
    {
        head = newnode;
    } 

    else 
    {
        node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}


void displayfwd(node* head) 
{
    node* temp = head;
    cout << "Forward: ";

    while (temp != nullptr) 
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

void displayrev(node* head) 
{
    node* temp = head;

    if (temp == nullptr) 
    {
        return;
    }

    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    cout << "Reverse: ";

    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main() 
{
    node* head = nullptr; 
    insertdata(head, 10);
    insertdata(head, 20);
    insertdata(head, 30);
    insertdata(head, 40);

    cout << "Doubly Linked List: "<<endl;
    displayfwd(head);
    cout<<endl;
    displayrev(head);

    return 0;
}

~~~
2).circular linked list<br>

~~~
#include <iostream>
using namespace std;

struct node 
{
    int data;     
    node* next;  
};

node* createnode(int value) 
{
    node* newnode = new node(); 
    newnode->data = value;      
    newnode->next = nullptr;    
    return newnode;
}

void insertdata(node*& head, int value) 
{
    node* newnode = createnode(value);

    if (head == nullptr) 
    {
        head = newnode;
        newnode->next = head; 
    } 
    
    else 
    {
        
        node* temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void display(node* head) 
{
    if (head == nullptr) 
    {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = head;

    do 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } 
    while (temp != head);

    cout << "(back to head)" << endl;
}

int main() 
{
    node* head = nullptr;

    insertdata(head, 10);
    insertdata(head, 20);
    insertdata(head, 30);
    insertdata(head, 40);

    
    cout << "Circular Linked List: ";
    display(head);

    return 0;
}


