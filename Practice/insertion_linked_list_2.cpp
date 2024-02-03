//INSERTION OF LINKED LIST AT SPECIFIC POSITION
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
    int new_ele;
    cout<<endl<<"Enter the number to insert: ";cin>>new_ele;
    struct Node*p1=(struct Node*)malloc(sizeof(struct Node));
    p1=head;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    int pos;
    cout<<endl<<"Enter position: ";cin>>pos;
    int count=0;
    while(p1!=NULL)
    {
        count++;
        if(pos==1)
        {
            newnode->data=new_ele;
            newnode->next=head;
            head=newnode;
            break;
        }
        else if(count==pos-1)
        {
            newnode->data=new_ele;
            newnode->next=p1->next;
            p1->next=newnode;
        }
        p1=p1->next;
    }
    temp=head;
    cout<<endl<<"The linked list after insertion is ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}