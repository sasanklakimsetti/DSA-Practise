//IMPLEMENTATION  OF QUEUE USING LINKED LIST
//Enqueue: insertion from rear end of queue
//Dequeue: deletion from front end of queue
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*front,*rear;
void enqueue(int value)
{
    Node *newnode=new Node();
    newnode->data=value;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    struct Node *temp=front;
    if(front==NULL)
    {
        cout<<"Queue is empty. "<<endl;
    }
    else
    {
        cout<<"The deleted element is "<< front->data<<endl;  //deletion happens from front in queue.
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        free(temp);
    }
}
void display()
{
    struct Node *temp=front;
    if(temp==nullptr)
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        cout<<"The queue is ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            cin>>value;
            enqueue(value);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}