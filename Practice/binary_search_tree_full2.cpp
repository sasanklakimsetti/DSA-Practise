#include<iostream>
using namespace std;
struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
};
//Function to insert a node in a binary search tree
struct Tree* insertNode(Tree* node,int k)
{
    if(node==nullptr)
    {
        struct Tree* newnode=new Tree();
        newnode->data=k;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    else
    {
        if(k<node->data) node->left=insertNode(node->left,k);
        else if(k>node->data) node->right=insertNode(node->right,k);
        return node;
    }
}
//Function to search a node in a binary search tree
struct Tree* searchNode(Tree* node, int k)
{
    if(node==NULL) return NULL;
    if(k==node->data) return node;
    else if(k<node->data) return searchNode(node->left,k);
    else if(k>node->data) return searchNode(node->right,k);
}
//Function to find inOrderSuccessor of a binary search tree
struct Tree* inOrderSuccessor(Tree* node)
{
    while(node->left)
    {
        node=node->left;
    }
    return node;
}
//Function to delete a node in a binary search tree
struct Tree* deleteNode(Tree* node, int k)
{
    if(node==NULL) return node;
    if(k<node->data) deleteNode(node->left,k);
    else if(k>node->data) deleteNode(node->right,k);
    else
    {
        if(node->left==NULL)
        {
            struct Tree* temp=node->right;
            delete node;
            return temp;
        }
        else if(node->right==NULL)
        {
            struct Tree* temp=node->left;
            delete node;
            return temp;
        }
        else
        {
            struct Tree* temp=inOrderSuccessor(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data);
        }
    }
    return node;
}
void printInorder(Tree* node)
{
    if(node==NULL) return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}
void printPreorder(Tree* node)
{
    if(node==NULL) return;
    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostorder(Tree* node)
{
    if(node==NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}
int main()
{
    struct Tree* node=NULL;
    int choice,data;
    while(1)
    {
        cout<<"\n1.Insertion a node\n2.Search a node\n3.Delete a node\n4.In-order Traversal\n5.Pre-order Traversal\n6.Post-order Traversal\n7.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";
            cin>>data;
            node=insertNode(node,data);
            break;
            case 2:
            {
                cout<<"Enter node to search: ";
                cin>>data;
                struct Tree* result=searchNode(node,data);
                if(result==NULL) cout<<"Not found\n";
                else cout<<"Found\n";
            }
            break;
            case 3:
            cout<<"Enter node to delete: ";
            cin>>data;
            node=deleteNode(node,data);
            break;
            case 4:
            cout<<"The inorder traversal of tree is ";
            printInorder(node);
            cout<<endl;
            break;
            case 5:
            cout<<"The preorder traversal of tree is ";
            printPreorder(node);
            cout<<endl;
            break;
            case 6:
            cout<<"The postorder traversal of tree is ";
            printPostorder(node);
            cout<<endl;
            break;
            case 7:
            exit(0);
            break;
        }
    }
}