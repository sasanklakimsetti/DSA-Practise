//DELETION OF LINKED LIST AT END
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
    cout<<endl<<"Enter the elements of the linked list: ";
    struct Node*head=NULL,*temp=NULL;
    int ele;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
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
    int count=0;
    struct Node*p1=(struct Node*)malloc(sizeof(struct Node));
    p1=head;
    while(p1!=NULL)
    {
        count++;
        if(count==n-1)
        {
            p1->next=NULL;
        }
        p1=p1->next;
    }
    cout<<endl<<"The linked list after deletion at end: ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}