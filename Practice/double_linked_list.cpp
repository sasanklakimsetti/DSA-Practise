//TRAVERSAL OF DOUBLE LINKED LIST
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
    cout<<"Enter the size of linked list: ";cin>>n;
    struct Node*head=NULL,*temp=NULL;
    cout<<endl<<"Enter the elements of the linked list: ";
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
    temp=head;
    cout<<endl<<"The linked list is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}