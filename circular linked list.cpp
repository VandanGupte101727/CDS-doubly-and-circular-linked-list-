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
