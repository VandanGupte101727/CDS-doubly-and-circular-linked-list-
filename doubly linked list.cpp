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
