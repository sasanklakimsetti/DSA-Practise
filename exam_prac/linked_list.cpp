#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
}*head=NULL,*temp=NULL;
void insertion(Node *n, int k)
{
    Node* newnode= new Node();
    newnode->data=k;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void insertion_Beginning(Node *n, int k)
{
    Node*newnode=new Node();
    newnode->data=k;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        temp=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        temp=newnode;
    }
}
void insertion_End(Node* node, int k)
{
    Node *newnode=new Node();
    newnode->data=k;
    newnode->next=NULL;
    if(head==NULL)
    {
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
    }
}
void insertion_Pos(Node*n, int k, int pos)
{
    Node* newnode=new Node();
    newnode->data=k;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        int count=1;
        temp=head;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int Deletion_Beginning(Node* n)
{
    Node* newnode=new Node();
    temp=head;
    if(head==NULL) return -1;
    else
    {
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
}
int Deletion_End(Node *n)
{
    Node* newnode=new Node();
    if(head==NULL) return -1;
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        delete temp->next;
    }
}
int Deletion_Pos(Node* n,int pos)
{
    if(head==NULL) return -1;
    else if(pos==1)
    {
        temp=head;
        delete temp;
    }
    else
    {
        int count=1;
        temp=head;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        temp->next=temp->next->next;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int data,pos;
    Node* newnode=new Node();
    while(true)
    {
        cout<<"1.Add Node\n2.Insertion at beginning\n3.Insertion at end\n4.Insertion at position\n5.Deletion at beginning\n6.Deletion at end\n7.Deletion at position\n8.Display\n9.exit\n";
        cout<<"Enter choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";
            cin>>data;
            insertion(newnode,data);
            break;
            case 2:
            cout<<"Enter data: ";
            cin>>data;
            insertion_Beginning(newnode,data);
            break;
            case 3:
            cout<<"Enter data: ";cin>>data;
            insertion_End(newnode,data);
            break;
            case 4:
            cout<<"Enter data: ";
            cin>>data;
            cout<<"Enter position: ";cin>>pos;
            insertion_Pos(newnode,data,pos);
            break;
            case 5:
            Deletion_Beginning(newnode);
            break;
            case 6:
            Deletion_End(newnode);
            break;
            case 7:
            cout<<"Enter position: ";cin>>pos;
            Deletion_Pos(newnode,pos);
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