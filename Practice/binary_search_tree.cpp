//IMPLEMENTATION OF BINARY SEARCH TREE
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node* insert(struct Node* root, int data)
{
    if(root==NULL)
    {
        struct Node* newnode=new Node();
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
struct Node* search(struct Node *root,int data)
{
    if(root==NULL||root->data==data) return root;
    if(data<root->data) return search(root->left,data);
    else return search(root->right,data);
    return root;
}
void printInorder(Node *node)
{
    if(node==NULL) return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}
void printPreorder(Node *node)
{
    if(node==NULL) return ;
    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostOrder(Node* node)
{
    if(node==NULL) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->data<<" ";
}
int main()
{
    struct Node *root=NULL;
    int choice,data;
    cout<<"1.Insertion\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.exit\n";
    while(true)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            root=insert(root,data);
            break;
            case 2:
            cout<<"Enter data to search: ";cin>>data;
            root=search(root,data);
            cout<<root<<endl;
            break;
            case 3:
            cout<<"The inorder traversal is ";
            printInorder(root);
            cout<<endl;
            break;
            case 4:
            cout<<"The preorder traversal is ";
            printPreorder(root);
            cout<<endl;
            break;
            case 5:
            cout<<"The postorder traversal is ";
            printPostOrder(root);
            cout<<endl;
            break;
            case 6:
            exit(0);
            break;
        }
    }
}