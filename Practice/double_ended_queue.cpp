//IMPLEMENTATION OF DOUBLE ENDED QUEUE USING LINKED LIST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}*front=NULL,*rear=NULL;
void enqueueAtBegin(int k)
{
    struct Node* newnode=new Node();
    newnode->data=k;
    newnode->prev=NULL;
    if(front==NULL&&rear==NULL)
    {
        newnode->next=NULL;
        rear=newnode;
    }
    else
    {
        newnode->next=front;
        front->prev=newnode;
    }
    front=newnode;
}
void enqueueAtEnd(int k)
{
    struct Node* newnode=new Node();
    newnode->data=k;
    newnode->next=NULL;
    if(rear==NULL)
    {
        rear=front=newnode;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=rear;
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeueAtBegin()
{
    if(front==NULL&&rear==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"The dequeued element is "<<front->data<<endl;
        front=front->next;
        delete front;
        front->prev=NULL;
        if(front==NULL)
        {
            rear=NULL;
        }
    }
}
int dequeueAtEnd()
{
    if(front==NULL&&rear==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"The dequeued element is "<<rear->data<<endl;
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
        if(rear==NULL)
        {
            front=NULL;
        }
    }
}
void display()
{
    struct Node* temp=front;
    if(temp==NULL)
    {
        cout<<"Queue is empty\n";
    }
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
    cout<<"1.Enqueue at beginning\n2.Enqueue at end\n3.Dequeue at beginning\n4.Dequeue at end\n5.Display\n6.exit\n";
    int choice;
    int data;
    while(1)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            enqueueAtBegin(data);
            break;
            case 2:
            enqueueAtEnd(data);
            break;
            case 3:
            dequeueAtBegin();
            break;
            case 4:
            dequeueAtEnd();
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
            break;
        }
    }
}