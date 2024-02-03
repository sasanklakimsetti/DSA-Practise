#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    int n,ele;
    cout<<"Enter size of the linked list: ";
    cin>>n;
    struct Node *head=NULL,*temp=NULL;
    cout<<endl<<"Enter the elements of the linked list: ";
    for(int i=0;i<n;i++)
    {
        struct Node *newnode= (struct Node*) malloc(sizeof(struct Node));
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
    cout<<endl<<"The linked list is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}