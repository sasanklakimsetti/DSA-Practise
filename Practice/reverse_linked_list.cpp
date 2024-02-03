//REVERSAL OF LINKED LIST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
};
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    struct Node*head=NULL,*temp=NULL;
    cout<<endl<<"Enter the elements of the linked list: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
        if(head==NULL)
        {
            newnode->data=ele;
            newnode->next=NULL;
            head=newnode;
            temp=newnode;
        }
        else
        {
            newnode->data=ele;
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
        }
    }
    cout<<endl<<"The linked list is ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    struct Node*prev=NULL;
    struct Node*current=head;
    struct Node*next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    cout<<endl<<"The linked list after reversing ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}