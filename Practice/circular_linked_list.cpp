#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void insert(Node** head, int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        Node* temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int main()
{
    Node* head = NULL;
    int count = 0;

    while(true)
    {
        int data;
        cin >> data;
        if(cin.eof())  // break the loop if there's no more input
        {
            break;
        }
        insert(&head, data);
    }

    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << count << endl;

    Node *headernode = new Node();
    headernode->data = count;
    headernode->next = head;
    head = headernode;

    temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
