#include<iostream>
using namespace std;
struct Node
{
    int data;
    int priority;
    struct Node *next;
}*front,*temp,*rear;
void enqueue(int data, int p)
{
    Node *newnode=new Node();
    newnode->data=data;
    newnode->priority=p;
    if(front==NULL&&rear==NULL)
    {
        newnode->next=NULL;
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
        while(temp->next->next!=NULL&&newnode->priority<=temp->priority)
        {
            temp=temp->next;
        }
        if(temp->next==nullptr)
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
    if(front==rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        Node* temp=front;
        cout<<"The dequeued element is "<<front->data<<endl;
        front=front->next;
        free(temp);
    }
}
void display()
{
    if(front==NULL&&rear==NULL) cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"the queue is ";
        Node* temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
void peek()
{
    if(front==NULL&&rear==NULL) cout<<"queue is empty"<<endl;
    else
    {
        cout<<"The element with highest priority is "<<front->data<<endl;
    }
}
int main()
{
    int data,priority,choice;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.exit\n";
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
            cout<<endl;
            break;
            case 4:
            peek();
            break;
            case 5:
            exit(0);
            break;
        }
    }
}