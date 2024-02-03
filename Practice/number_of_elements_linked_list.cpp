//NUMBER OF ELEMENTS PRESENT IN A LINKED LIST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
};
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    struct Node*head=NULL,*temp=NULL;
    cout<<endl<<"Enter the elements of the linked list: ";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
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
    cout<<endl<<"The linked list is ";
    temp=head;
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
        p1=p1->next;
    }
    cout<<endl<<"Number of elements in the linked list: "<<count;
}