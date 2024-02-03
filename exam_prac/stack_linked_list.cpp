#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
}*top=NULL;
bool isEmpty()
{
    if(top==NULL)  return 1;
    else return 0;
}
void push(int data)
{
    Node* newnode=new Node();
    if(newnode!=NULL)
    {
        newnode->data=data;
        newnode->next=top;
        top=newnode;
    }
    else
    {
        cout<<"stack overflow\n";
    }
}
int pop()
{
    Node *temp=top;
    if(isEmpty()) cout<<"Stack is empty"<<endl;
    else
    {
        int val=temp->data;
        top=top->next;
        free(temp);
        temp=NULL;
        return val;
    }
}
int peek()
{
    if(isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        return top->data;
    }
}
void display()
{
    if(isEmpty()) cout<<"Stack is empty"<<endl;
    else
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int main()
{
    int data,choice,k;
    while(1)
    {
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data to push: ";cin>>data;
            push(data);
            break;
            case 2:
            k=pop();
            cout<<"Popped element is "<<k<<endl;
            break;
            case 3:
            k=peek();
            cout<<"The peek element of the stack is "<<k<<endl;
            break;
            case 4:
            display();
            cout<<endl;
            break;
            case 5:
            exit(0);
            break;
        }
    }
}