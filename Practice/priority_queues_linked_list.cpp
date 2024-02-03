//IMPLEMENTATION OF PRIORITY QUEUE USING LINKED LIST
#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    int priority;
    struct Node* next;
}*front,*rear,*temp;
void enqueue(int k,int p)
{
    struct Node* newnode=new Node();
    newnode->data=k;
    newnode->priority=p;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=newnode;
    }
    else if(newnode->priority>front->priority)
    {
        newnode->next=front;
        front=newnode;
    }
    else
    {
        temp=front;
        while(temp->next!=NULL&&newnode->priority<=temp->priority)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next=newnode;
            rear=newnode;
        }
        else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void dequeue()
{
    temp=front;
    if(front==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"The dequeued element is "<<front->data<<endl;
        temp=temp->next;
        free(temp);
    }
}
void display()
{
    temp=front;
    if(temp==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else 
    {
        cout<<"The priority queue is ";
        while(temp!=NULL)
        {
            cout<<"Data: "<<temp->data<<" Priority: "<<temp->priority<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
}
void peek()
{
    cout<<front->data<<endl;
}
int main()
{
    cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.exit\n";
    int choice,data,priority;
    while(1)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            cout<<"Enter priority: ";cin>>priority;
            enqueue(data,priority);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            cout<<"The element with highest priority is ";
            peek();
            break;
            case 5:
            exit(0);
            break;
        }
    }
}