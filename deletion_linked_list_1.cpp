//DELETION OF AN ARRAY FROM BEGINNING
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    cout<<"Enter the size of the linked list: ";
    int n;
    cin>>n;
    struct Node* head=NULL,*temp=NULL;
    int ele;
    cout<<endl<<"Enter the elements of the linked list: ";
    for(int i=0;i<n;i++)
    {
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        cin>>ele;
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
    cout<<endl<<"The linked list is: ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    head=head->next;
    cout<<endl<<"The linked list after deletion from beginning: ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}