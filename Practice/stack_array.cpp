//IMPLEMENTING A STACK USING AN ARRAY
#include<iostream>
using namespace std;
const int MAX_SIZE=100;
int stack[MAX_SIZE];
int top=-1;
bool isFull()
{
    return top==MAX_SIZE-1;
}
bool isEmpty()
{
    return top==-1;
}
void push(int value)
{
    if(!isFull())
    {
        stack[++top]=value;
    }
    else
    {
        cout<<"Stack is full. Cannot push element into the stack";
    }
}
int pop()
{
    if(!isEmpty())
    {
        return stack[top--];
    }
    else 
    {
        cout<<"Stack is empty. Cannot pop";
        return -1;
    }
}
void display()
{
    if(!isEmpty())
    {
        cout<<"The stack is ";
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
    }
    else
    {
        cout<<"Stack is empty";
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the stack: ";cin>>n;
    int element;
    cout<<endl<<"Enter the elements of the stack"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        push(element);
    }
    display();
}