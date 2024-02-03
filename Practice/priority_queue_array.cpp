//IMPLEMENTATION OF PRIORITY QUEUE USING  AN ARRAY
#include<iostream>
using namespace std;
//Structure to implement array
struct priorityQueue
{
    int ele;
    int priority;
}pq[5];
int rear=-1;
int isEmpty()
{
    if(rear==-1) return 1;
    else return 0;
}
int isFull()
{
    if(rear==4) return 1;
    else return 0;
}
void insert(int ele, int p)
{
    rear=rear+1;
    pq[rear].ele=ele;
    pq[rear].priority=p;
}
int getHighestPriority()
{
    int i,p=-1;
    if(!isEmpty())
    {
        for(i=0;i<=rear;i++)
        {
            if(pq[i].priority>p)
            {
                p=pq[i].priority;
            }
        }
        return p;
    }
}
int deleteHighestPriority()
{
    int i,j,p,ele;
    p=getHighestPriority();
    for(i=0;i<rear;i++)
    {
        if(pq[i].priority==p)
        {
            ele=pq[i].ele;
            break;
        }
    }
    if(i<rear)
    {
        for(j=i;j<rear;j++)
        {
            pq[j].ele=pq[j+1].ele;
            pq[j].priority=pq[j+1].priority;
        }
    }
}
void display()
{
    int i;
    cout<<"Priority Queue: ";
    for(i=0;i<rear;i++)
    {
        cout<<pq[i].ele<<" "<<pq[i].priority<<endl;
    }
}
int main()
{
    int ch,p,ele;
    do
    {
        cout<<"\n1.Insert\n2.GetHighestPriority\n3.DeleteHighestPriority\n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            if(isFull())
            {
                cout<<"Priority Queue is full";
            }
            else
            {
                cout<<"Enter the element to insert: ";cin>>ele;
                cout<<"Enter priority: ";cin>>p;
                insert(ele,p);
            }
            break;
            case 2:
            if(isEmpty())
            {
                cout<<"Priority Queue is empty";
            }
            else
            {
                p=getHighestPriority();
                cout<<"Highest Priority: "<<p;
            }
            break;
            case 3:
            if(isEmpty())
            {
                cout<<"Priority queue is empty";
            }
            else
            {
                ele=deleteHighestPriority();
                cout<<ele<<" is deleted";
            }
            break;
            case 4:
            if(isEmpty())
            {
                cout<<"Priority queue is empty";
            }
            else
            {
                display();
            }
            break;
            case 5:
            exit(0);
            break;
        }
    }
    while(ch!=5);
}