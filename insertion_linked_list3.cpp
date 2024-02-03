//INSERTION OF AN ARRAY AT A SPECIFIC POSITION
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
    int ele;
    struct Node *head=NULL,*temp=NULL;
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
    cout<<endl<<"The linked list: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<"Enter the element to be inserted: ";
    int new_element;
    cin>>new_element;
    cout<<endl<<"Enter the position in which the element to be inserted: ";
    int pos;
    cin>>pos;
    int count=0;
    struct Node* p1=(struct Node*)malloc(sizeof(struct Node));
    p1=head;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    while(p1!=NULL)
    {
        count++;
        if(pos==1)
        {
            newnode->data=new_element;
            newnode->next=head;
            head=newnode;
            break;
        }
        else if(count==pos-1)
        {
            newnode->data=new_element;
            newnode->next=p1->next;
            p1->next=newnode;
            break;
        }
        p1=p1->next;
    }
    cout<<endl<<"The linked list after insertion: ";
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}