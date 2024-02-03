#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
}*front=NULL,*rear=NULL;
void enqueue(int data)
{
    Node *newnode=new Node();
    if(front==NULL&&rear==NULL)
    {
        newnode->data=data;
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
    }
    else
    {
        newnode->data=data;
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
    }
}
int dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        Node* temp=front;
        cout<<"The dequeued element is "<<temp->data<<endl;
        front=front->next;
        if(front==NULL) rear=NULL;
        free(temp);
    }
}
void display()
{
    Node* temp=front;
    if(temp==NULL) cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"The queue is ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int main()
{
    int data,choice;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            cout<<endl;
            break;
            case 4:
            exit(0);
            break;
        }
    }
}