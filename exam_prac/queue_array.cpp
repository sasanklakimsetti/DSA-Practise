#include<iostream>
using namespace std;
#define size 100
int queue[size];
int front=0;
int rear=0;
void enqueue(int data)
{
    if(rear==size)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        queue[rear]=data;
        rear++;
    }
}
int dequeue()
{
    if(front==rear) cout<<"Queue is empty"<<endl;
    else
    {
        int k=queue[front];
        for(int i=front;i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
        return k;
    }
}
void display()
{
    if(front==rear) cout<<"Queue is empty"<<endl;
    else
    {
        int i=front;
        while(i!=rear)
        {
            cout<<queue[i]<<" ";
            i++;
        }
    }
}
int main()
{
    int choice;
    int data;
    int k;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";
            cin>>data;
            enqueue(data);
            break;
            case 2:
            k=dequeue();
            cout<<"Dequeued element is "<<k<<endl;
            break;
            case 3:
            cout<<"The queue is ";
            display();
            cout<<endl;
            break;
            case 4:
            exit(0);
            break;
        }
    }
}