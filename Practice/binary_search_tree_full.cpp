#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right; 
};
struct Node* insertNode(Node* root,int k)
{
    if(root==NULL)
    {
        struct Node* newnode=new Node();
        newnode->data=k;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    if(k<root->data)
    {
        root->left=insertNode(root->left,k);
    }
    else if(k>root->data)
    {
        root->right=insertNode(root->right,k);
    }
    return root;
}
struct Node* inOrderSuccessor(Node* node)
{
    while(node->left)
    {
        node=node->left;
    }
    return node;
}
struct Node* deleteNode(Node* node,int k)
{
    if(node==NULL) return node;
    else if(k<node->data) deleteNode(node->left,k);
    else if(k>node->data) deleteNode(node->right,k);
    else
    {
        if(node->left==NULL)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right==NULL)
        {
            Node* temp=node->left;
            delete node;
            return temp;
        }
        else
        {
            Node* temp=inOrderSuccessor(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data);
        }
    }
    return node;
}

struct Node* searchNode(Node* node,int k)
{
    if(node==NULL||node->data==k) return node;
    if(k<node->data) return searchNode(node->left,k);
    else if(k>node->data) return searchNode(node->right,k);
}
void inOrder(Node* node)
{
    if(node==NULL) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
void preOrder(Node* node)
{
    if(node==NULL) return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
void postOrder(Node* node)
{
    if(node==NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    int choice;
    int data;
    struct Node* node= NULL;
    while(1)
    {
        cout<<"\n1.Insert a node\n2.Delete a node\n3.Search a node\n4.Inorder Traversal\n5.Preorder Traversal\n6.PostOrder Traversal\n7.Exit\n";
        cout<<"Enter choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";cin>>data;
            node=insertNode(node,data);
            break;
            case 2:
            cout<<"Enter node to delete: ";cin>>data;
            node=deleteNode(node,data);
            break;
            case 3:
            cout<<"Enter node to search: ";cin>>data;
            node=searchNode(node,data);
            cout<<node<<endl;
            break;
            case 4:
            inOrder(node);
            break;
            case 5:
            preOrder(node);
            break;
            case 6:
            postOrder(node);
            break;
            case 7:
            exit(0);
            break;
        }
    }
}