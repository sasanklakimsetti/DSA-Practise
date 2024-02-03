//INSERTION OF LINKED LIST AT BEGINNING
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    cout<<"Enter size of linked list: ";
    int n;
    cin>>n;
    cout<<endl<<"Enter the elements of linked list: ";
    struct Node *head=NULL,*temp=NULL;
    for(int i=0;i<n;i++)
    {
        struct Node *newnode=(struct Node*) malloc(sizeof(struct Node));
        int ele;
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
    cout<<endl<<"The Linked list is ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<"Enter the element to be inserted at beginning: ";
    int new_element;
    cin>>new_element;
    struct Node *newnode=(struct Node*) malloc(sizeof(struct Node));
    newnode->data=new_element;
    newnode->next=head;
    head=newnode;
    cout<<endl<<"The linked list after insertion: ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}