//IMPLEMENTATION OF A STACK USING LINKED LIST
//The code of the push() function must be similar to the code of inserting the node at the beginning of the singly linked list
//The new element will always be added in the head of the linked list as the time complexity of the insertion and deletion will be O(1).
//The code of pop() function must be similar to the code of deleting the first node of the singly linked list
//Stack Overflow : occurs when there is no space left to dynamically allocate the memory. In that case, malloc() function will return NULL.
//Stack Underflow: occurs when top is equal to NULL.
//Structure of the Node : same as the structure of node of a singly linked list
//Top variable: no need to declare top variable. Instead will replace the top variable by a pointer named top. This pointer must always point to the first node of the linked list

//Declaration of top pointer globally in the code : *top=NULL after structure declaration

/*push function: similar to the add_beg function of the singly linked list with small changes i.e. 
1.Create a new node
2.Put the address of the first node of the above linked list in the link part of the new code.
3. Update the top pointer and make it point to the new node of the linked list
*/

//Pop function: similar to del_first function of the singly linked list with small changes
/*
1.Create a temporary pointer for the purpose of deletion
2.Update the temporary pointer so that it can point to the first node of the linked list.
3.Store the value of the first node somewhere
4.Update the top pointer so that it can point to the next node of the linked list
5.Return the value of the first node
*/
#include<iostream>
#include<stack>
using namespace std;
//struct declaration
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;
//function used to check whether the stack is empty or not
int isEmpty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}
void push(int value) //function used to push an element into the stack
{
    struct Node*newnode=new Node();
    if(newnode!=NULL)
    {
        newnode->data=value;
        newnode->next=top; //top=head in linked list 
        top=newnode;
    }
    else
    {
        cout<<"Stack overflow.Cannot push"<<endl;
        exit(1);
    }
}
//function used to pop the element from the stack
int pop() //since we need to return the value of the head node. so we need to use the return type of function as int
{
    struct Node*temp;
    temp=top;
    if(!isEmpty())
    {
        int val=temp->data;
        top=top->next;
        delete temp; //deletion of the temporary element stored in the pointer
        temp=NULL;
        return val;
    }
    else
    {
        cout<<"Stack underflow. Cannot pop"<<endl;
    }
}
//function used to display the stack on the console
void display()
{
    struct Node*temp;
    temp=top;
    if(!isEmpty())
    {
        cout<<"The stack elements are ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    else 
    {
        cout<<"Stack is empty. Nothing to display"<<endl;
    }
}
int peek()
{
    if(isEmpty())
    {
        cout<<"Stack underflow."<<endl;
        exit(1);
    }
    else
    return top->data;
}
int main()
{
    int choice,data;
    while(1)
    {
        cout<<"1.Push\n2.Pop\n3.Print\n4.Top of the stack\n5.Quit\n";
        cout<<"Enter your choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the element to be pushed: ";cin>>data;
            push(data);
            break;
            case 2:pop();break;
            case 3:display(); break;
            case 4:
            cout<<"The top of the stack is "<<peek()<<endl;
            break;
            case 5:exit(1);
            break;
            default:
            cout<<"Wrong choice";
            break;
        }
    }
    return 0;
}
