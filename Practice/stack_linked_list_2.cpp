#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
Node* top=NULL;
void push(int k)
{
    struct Node* newnode=new Node();
    
    if(newnode!=NULL)
    {
        newnode->data=k;
        newnode->next=top;
        top=newnode;
    }
    else
    {
        cout<<"Stack overflow\n";
    }
}
int pop()
{
    struct Node* temp;
    temp=top;
    if(temp!=NULL)
    {
        top=top->next;
        free(temp);
        temp=NULL;
    }
    else
    {
        cout<<"Stack underflow\n";
    }
}
void display()
{
    struct Node* temp;
    temp=top;
    cout<<"The stack is ";
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    else cout<<"empty\n";
}
int peek()
{
    return top->data;
}
int main()
{
    int choice,data;
    cout<<"1.Push\n2.Pop\n3.Display\n4.Peek\n5.exit\n";
    while(1)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            cout<<"The peek element of stack is "<<peek()<<endl;
            break;
            case 5:
            exit(0);
            break;
        }
    }
}