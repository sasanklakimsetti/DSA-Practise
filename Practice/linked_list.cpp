//TRAVERSAL OF LINKED LIST
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
    cout<<endl<<"Enter \n1.Insertion at beginning\n2.Insertion at end\n3.Insertion at specific position\n4.Deletion at beginning\n5.Deletion at end\n6.Deletion at specific postion\n";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        //INSERTION AT BEGINNING
        {
        cout<<endl<<"Enter number to insert: ";
        int new_ele;
        cin>>new_ele;
        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=new_ele;
        newnode->next=head;
        head=newnode;
        temp=head;
        cout<<endl<<"The linked list after insertion: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        break;
        }
        case 2:
        {
        //INSERTION AT END
        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
        int new_ele;
        cout<<endl<<"Enter the element to be inserted: ";
        cin>>new_ele;
        newnode->data=new_ele;
        newnode->next=NULL;
        temp->next=newnode;
        temp=head;
        cout<<endl<<"The linked list after insertion: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        break;
        }
    }
}