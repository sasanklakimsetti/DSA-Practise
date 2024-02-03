#include<iostream>
using namespace std;
struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*head=NULL,*temp=NULL;
void addNode(Node* n,int k)
{
    struct Node *newnode=new Node();
    newnode->data=k;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->prev=NULL;
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}
void insertion_Beg(Node*n,int k)
{
    Node *newnode=new Node();
    temp=head;
    newnode->data=k;
    newnode->prev=NULL;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
    }
}
void insertion_End(Node *n, int k)
{
    Node *newnode=new Node();
    newnode->data=k;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->prev=NULL;
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
        temp->next=newnode;
        newnode->prev=temp->prev->next;
    }
}
void insertion_Pos(Node*n, int k, int p)
{
    Node *newnode=new Node();
    newnode->data=k;
    if(p==1)
    {
        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->next=NULL;
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp=head;
            newnode->prev=NULL;
            newnode->next=temp;
            temp->prev=newnode;
            head=newnode;
        }
    }
    else
    {
        int count=1;
        while(count<p-1)
        {
            temp=temp->next;
            count++;
        }
        newnode->next=temp->next;
        newnode->prev=temp->next->prev;
        temp->next=newnode;
        temp->next->prev=newnode;
    }
}
void deletion_Beg(Node *n)
{
    Node* newnode=new Node();
    if(head==NULL) cout<<"List is empty"<<endl;
    else
    {
        temp=head;
        head=temp->next;
        temp->next=NULL;
        temp->next->prev=NULL;
        delete temp;
    }
}
void deletion_End(Node* n)
{
    if(head==NULL) cout<<"List is empty"<<endl;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
    }
}
void deletion_Pos(Node *n,int pos)
{
    if(pos==1)
    {
        temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else 
    {
        int count=1;
        while(count<pos-1)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->next->prev=temp->next->prev;
    }
}
void display()
{
    temp=head;
    cout<<"The list is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* newnode=new Node();
    int choice,data,pos;
    while(1)
    {
        cout<<"1.Add node\n2.Insertion at Beginning\n3.Insertion at end\n4.Insertion at position\n5.Deletion at beginning\n6.Deletion at end\n7.Deletion at position\n8.Display\n9.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            addNode(newnode,data);
            break;
            case 2:
            cout<<"Enter data: ";cin>>data;
            insertion_Beg(newnode,data);
            break;
            case 3:
            cout<<"Enter data: ";cin>>data;
            insertion_End(newnode,data);
            break;
            case 4:
            cout<<"Enter data: ";cin>>data;
            cout<<"Enter position: ";cin>>pos;
            insertion_Pos(newnode,data,pos);
            break;
            case 5:
            deletion_Beg(newnode);
            break;
            case 6:
            deletion_End(newnode);
            break;
            case 7:
            cout<<"Enter position to be deleted: ";cin>>pos;
            deletion_Pos(newnode,pos);
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
        }
    }
}