#include<iostream>
using namespace std;
struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* insertNode(Node* n, int data)
{
    if(n==NULL)
    {
        struct Node * newnode =new Node();
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    else if(data<n->data)
    {
        n->left=insertNode(n->left,data);
    }
    else if(data>n->data)
    {
        n->right=insertNode(n->right,data);
    }
    return n;
}
struct Node* inorder(Node *n)
{
    if (n==NULL) return n;
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
struct Node* preorder(Node *n)
{
    if(n==NULL) return n;
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
}
struct Node* postorder(Node *n)
{
    if(n==NULL) return n;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
}
struct Node *inOrderSuccessor(Node *n)
{
    while(n->left)
    {
        n=n->left;
    }
    return n;
}
struct Node* deleteNode(Node *n, int k)
{
    if(n==NULL) return n;
    else if(k<n->data) n->left=deleteNode(n->left,k);
    else if(k>n->data) n->right=deleteNode(n->right,k);
    else
    {
        if(n->left==NULL)
        {
            Node* temp=n->right;
            delete n;
            return temp;
        }
        else if(n->right==NULL)
        {
            Node* temp=n->left;
            delete n;
            return temp;
        }
        else
        {
            Node *temp=inOrderSuccessor(n->right);
            n->data=temp->data;
            n->right=deleteNode(n->right,temp->data);
        }
    }
    return n;
}
int main()
{
    int data;
    int choice;
    struct Node *newnode =NULL;
    while(1)
    {
        cout<<"1.Add Node\n2.Delete Node\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal\n6.exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the element to be inserted: ";cin>>data;
            newnode=insertNode(newnode,data);
            break;
            case 2:
            cout<<"Enter the key value of node to be deleted: ";cin>>data;
            newnode=deleteNode(newnode,data);
            break;
            case 3:
            inorder(newnode);cout<<endl;
            break;
            case 4:
            preorder(newnode);cout<<endl;
            break;
            case 5:
            postorder(newnode);cout<<endl;
            break;
            case 6:
            exit(0);
            break;
        }
    }
}