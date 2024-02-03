//INSERTION OF ELEMENT IN LINKED LIST AT EN
#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
void printList(Node*head){
Node*temp = head;
while(temp){
cout <<temp->data<<" ";
temp = temp->next;
}
}
int main()
{
struct Node* head = NULL;
int n=5,k=2;
//insertion at the starting;

while(n--)
{
int x;
cin>>x;
struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
n1->data = x;
n1->next = head;
head = n1;
}

//k elements insertion at the end;
while(k--)
{
int x;
cin>>x;
struct Node *temp,*n2;
n2 = (struct Node*)malloc(sizeof(struct Node));
n2->data = x;
temp = head;
while(temp->next != NULL)
{
temp=temp->next;
}
temp->next = n2;
n2->next = NULL;
}

// insert at after the ith position
struct Node* cur,*temp,*n3 = (struct Node*)malloc(sizeof(struct Node));
int x,i;
cin>>x>>i;
n3->data = x;
temp = head;
i--;
while(i--)
{
temp = temp->next;
}
cur = temp->next;
temp->next = n3;
n3->next = cur;

printList(head);

return 0;
}