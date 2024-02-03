//IMPLEMENTATION OF DOUBLY LINKED LIST IN C++
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node* next;
}node;
node* head=NULL;
node* temp=NULL;
node* first=NULL;
node* tail=NULL;
//function to add node in linked list
//adding node takes place at end
void addnode(int k)
{
    node *newnode=new node();//allocation of memory to node
    newnode->data=k; //assigning value of k to data
    //next and prev ptr to null
    newnode->next=NULL;
    newnode->prev=NULL;
    ///if linked list is empty
    if(head==NULL)
    {
        head=newnode;
        first=head;
        tail=head;
    }
    //else insert at end of linked list
    else
    {
        temp=newnode;
        first->next=temp;
        temp->prev=first;
        first=temp;
        tail=temp;
    }
    i++; //increment no.of nodes in doubly linked list
}
//function to traverse doubly linked list
void traverse()
{
    //node points towards head node
    node* newnode=head;
    //while newnode is not null ,traverse and print node
    while(newnode!=nullptr)
    {
        cout<<newnode->data<<" ";
        newnode=newnode->next;
    }
    cout<<endl;
}
//function to insert a node at beginning of the linked list
void insertAtBeginning(int k)
{
    //allocate memory to node
    node* newnode=new node();
    //assigning value of k to data
    newnode->data=k;
    //next and prev node to NULL
    newnode->next=NULL;
    newnode->prev=NULL;
    //if head is NULL
    if(head==NULL)
    {
        first=newnode;
        first=head;
        tail=head;
    }
    //else insert at beginning
    else
    {
        temp=newnode;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    i++;
}
//function to insert a node at end
void insertAtEnd()
{
    //allocation of memory to node
    node* newnode=new node();
    //next and prev to NULL
    newnode->next=NULL;
    newnode->prev=NULL;
    //if head is null
    if(head==NULL)
    {
        head=newnode;
        first=head;
        tail=head;
    }
    //else insert at end
    else
    {
        temp=newnode;
        temp->prev=tail;
        tail->next=temp;
        tai=temp;
    }
    i++;
}
//function to insert a node at specific position
void insertAtPosition(int k, int pos)
{
    //for invalid position
    if(pos<1||pos>i+1)
    {
        cout<<"Invalild position\n";
    }
    //if position is at front then call insertAtBeginning();
    if(pos==1)
    {
        insertAtBeginning(k);
    }
    //if position is at length of linked list+1, insert at end
    else if(pos==i+1)
    {
        insertAtEnd(k);
    }
    //else traverse till position pos and insert the node
    else
    {
        node* src=head;
        //move head ptr to pos
        while(pos--)
        {
            src = src->next;
        }
        //allocate memory to new node
        node **da, **ba;
        node* newnode=new node();
        newnode->next=NULL;
        newnode->prev=NULL;
        newnode->data=k;
        ba=&src;
        da=&(src->prev);
        newnode->next=(*ba);
        newnode->prev=(*da);
        (*da)->next=newnode;
        (*ba)->prev=newnode;
        i++;
    }
}
//function to delete a node from beginning of the linked list
void deleteAtBegin()
{
    //move head to next and decrease length by 1
    head=head->next;
    i--;
}
//function to delete node at end
void deleteAtEnd()
{
    //movie tail to prev and decrease length by 1
    tail=tail->prev;
    tail->next=NULL;
    i--;
}
//function to delete a node at specific position of a linked list
void deleteAtPos(int k, int pos)
{
    //if invalid position
    if(pos<1||pos>i+1)
    {
        cout<<"Invalid position\n";
    }
    //if position is 1 then call deleteAtBegin();
    else if(pos==1)
    {
        deleteAtBegin();
    }
    //if position is at end, call deleteAtEnd();
    else if(pos==i)
    {
        deleteAtEnd();
    }
    //else traverse till position and delete the node at pos
    else
    {
        node*src=head;
        pos--;
        while(pos--)
        {
            src=src->next;
        }
        node **pre,**aft;
        pre=&(src->prev);
        aft=&(src->next);
    }
}