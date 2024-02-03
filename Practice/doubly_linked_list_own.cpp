//IMPLEMENTATION OF DOUBLY LINKED LIST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
Node *head=NULL;
Node* temp=NULL;
//function to add a node at end
void addNode(int k)
{
    //allocation of memory to node
    struct Node* newnode=new Node();
    if(head==NULL)
    {
        newnode->data=k;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->data=k;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=NULL;
    }
}
//function to traverse the linked list
void traverse()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//function to insert a node at beginning of the linked list
void insertAtBegin(int k)
{
    struct Node* newnode=new Node();
    if(head==NULL)
    {
        newnode->data=k;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp=newnode;
        temp->data=k;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
//function to insert a node at end
void insertAtEnd(int k)
{
    //allocation of memory
    struct Node* newnode=new Node();
    if(head==NULL)
    {
        newnode->data=k;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->data=k;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
//function to insert a node at a specific position
void insertAtPos(int k, int pos)
{
    //allocation of memory
    int i=1;
    struct Node* newnode=new Node();
    if(pos<1)
    {
        cout<<"Invalid position\n";
    }
    else if(pos==1)
    {
        if(head==NULL)
        {
            newnode->data=k;
            newnode->prev=NULL;
            newnode->next=NULL;
            head=newnode;
        }
        else
        {
            newnode->data=k;
            newnode->prev=NULL;
            newnode->next=head;
            head->prev=newnode;
        }
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(pos>i+1)
        {
            cout<<"Invalid position\n";
        }
        else if(pos==i+1)
        {
            newnode->data=k;
            newnode->prev=temp;
            temp->next=newnode;
            newnode->next=NULL;
        }
        else if(pos>1||pos<i+1)
        {
            newnode->data=k;
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
        }
    }
}
void deleteAtBegin()
{
    head=head->next;
}
void deleteAtEnd()
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
    }
    else if(head->next==NULL)
    {
        delete head;
        head =NULL;
    }
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}
//function to delete a node at specific position
void deleteAtPos(int pos)
{
    if(pos==1)
    {
        head=head->next;
    }
    else if(pos<1)
    {
        cout<<"Invalid position\n";
    }
    else
    {
        temp=head;
        int i=1;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        if(pos==i+1)
        {
            deleteAtEnd();
        }
        else if(pos>1||pos<i+1)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
        else if(pos>i+1)
        {
            cout<<"Invalid position\n";
        }
    }
}
int main()
{
    int choice, data,pos;
    cout<<"1.Add Node\n2.Display\n3.Insertion at beginning\n4.Insertion at end\n5.Insertion at specific position\n6.Deletion at beginning\n7.Deletion at end\n8.Deletion at specific position\n9.Exit\n";
    while(1)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch (choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            addNode(data);
            break;
            case 2:
            cout<<"The linked list is ";
            traverse();
            break;
            case 3:
            cout<<"Enter element to insert at beginning: ";cin>>data;
            insertAtBegin(data);
            break;
            case 4:
            cout<<"Enter element to insert at end: ";cin>>data;
            insertAtEnd(data);
            break;
            case 5:
            cout<<"Enter position to insert: ";cin>>pos;
            cout<<"Enter data to be inserted: ";cin>>data;
            insertAtPos(data,pos);
            break;
            case 6:
            deleteAtBegin();
            break;
            case 7:
            deleteAtEnd();
            break;
            case 8:
            cout<<"Enter position to be deleted: ";cin>>pos;
            deleteAtPos(pos);
            break;
            case 9:
            exit(0);
            break;
        }
    }
}