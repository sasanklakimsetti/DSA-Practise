//DELETION OF LINKED LIST AT A SPECEFIC POSITION
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
    int ele;
    cout<<endl<<"Enter the elements of the linked list: ";
    struct Node*head=NULL,*temp=NULL;
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
    temp=head;
    cout<<endl<<"The linked list is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<"Enter the position in which the element to be deleted: ";
    int pos;
    cin>>pos;
    int count=0;
    struct Node* p1=(struct Node*)malloc(sizeof(struct Node));
    p1=head;
    while(p1!=NULL)
    {
        count++;
        if(pos==1)
        {
            head=p1->next;
            break;
        }
        else if(count==pos-1)
        {
            p1->next=p1->next->next;
            break;
        }
        p1=p1->next;
    }
    cout<<endl<<"The linked list after deletion is ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}