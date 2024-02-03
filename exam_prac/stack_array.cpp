#include<iostream>
using namespace std;
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top=-1;
bool is_full()
{
    return top==MAX_SIZE-1;
}
bool isempty()
{
    return top==-1;
}
void push(int data)
{
    if(is_full())
    {
        cout<<"Stack is full. no pushing\n";
    }
    else
    {
        stack[++top]=data;
    }
}
int pop()
{
    if(isempty())
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        return stack[top--];
    }
}
void peek()
{
    if(isempty())
    {
        cout<<"Stack is empty";
    }
    else
    {
        cout<<stack[top]<<endl;
    }
}
void display()
{
    if(!isempty())
    {
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
    }
    else
    {
        cout<<"Stack is empty"<<endl;
    }
}
int main()
{
    int data,choice,k;
    while(true)
    {
        cout<<"1.Push\n2.Pop\n3.Display\n4.Peek\n5.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            push(data);
            break;
            case 2:
            k=pop();
            cout<<"Popped element is "<<k<<endl;
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