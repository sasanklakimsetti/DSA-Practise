//INSERTION OF AN ELEMENT IN THE LINKED LIST
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
void printList(Node* head)
{
    //print list
    Node*temp = head;
    while(temp)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    int n = 5;
    //insertion at starting
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node*));
    head = n1;
    n1 -> next = head;
    head = n1;

    printList(head);
    return 0;
}