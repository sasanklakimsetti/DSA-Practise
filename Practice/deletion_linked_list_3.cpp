//DELETION OF LINKED LIST AT SPECIFIC POSITION
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
    int pos;
    cout<<endl<<"Enter the position to be deleted: ";
    cin>>pos;
    struct Node*p1=(struct Node*)malloc(sizeof(struct Node));
    p1=head;
    int count=0;
    while(p1!=NULL)
    {
        count++;
        if(pos==1)
        {
            head=p1->next;
            break;
        }
        else if(count==pos)
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