//DELETION OF LINKED LIST AT BEGINNING
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    int n;
    cout<<"Enter size of linked list: ";
    cin>>n;
    struct Node*head=NULL,*temp=NULL;
    int ele;
    cout<<endl<<"Enter elements of the linked list: ";
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
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
    temp=head;
    cout<<endl<<"The linked list is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=head->next;
    temp=head;
    cout<<endl<<"The linked list after deletion is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}