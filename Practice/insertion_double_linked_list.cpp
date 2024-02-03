//INSERTION OF DOUBLE LINKED LIST AT BEGINNING
#include<iostream>
using namespace std;
struct Node
{
    struct Node*prev;
    int data;
    struct Node*next;
};
int main()
{
    int n;
    cout<<"Enter the size of the linked list: ";cin>>n;
    struct Node*temp=NULL,*head=NULL;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->data=ele;
            newnode->next=NULL;
            head=newnode;
            temp=newnode;
        }
        else
        {
            newnode->data=ele;
            newnode->next=NULL;
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }
    }
    cout<<endl<<"The linked list is ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";temp=temp->next;
    }
    cout<<endl<<"Enter the element to be inserted: ";
    int new_ele;
    cin>>new_ele;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=new_ele;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}