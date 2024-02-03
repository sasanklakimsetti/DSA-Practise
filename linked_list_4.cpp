#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;

Node(int x)
{
data = x;
next = NULL;
}
};
int main()
{
//dynamically allocation
Node* head = (Node*)malloc(sizeof(Node));
//using constructoer
Node* head1 = new Node(10);
head->data = 10;
cout<<head->data<<endl;
return 0;
}