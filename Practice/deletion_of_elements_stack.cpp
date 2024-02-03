//DELETION OF ELEMENT AT A SPECIFIC POSITION USING STACKS
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n,ele;
    stack<int>s;
    cout<<"Enter the size of stack: ";cin>>n;cout<<"Enter the elements of the stack: ";
    for(int i=1;i<=n;i++)
    {
        cin>>ele;
        s.push(ele);
    }
    cout<<endl<<"Enter the position to be deleted: ";
    int pos;
    cin>>pos;
    stack<int>temp;
    for(int i=1;i<pos;i++)
    {
        temp.push(s.top());
        s.pop();
    }
    s.pop();
    n--;
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    cout<<endl;
    cout<<"The stack after deletion at "<<pos<<"th position is ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}