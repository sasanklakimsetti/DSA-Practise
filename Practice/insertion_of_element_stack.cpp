//INSERTION OF ELEMENT AT SPECIFIC POSITION USING STACKS
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    stack<int>temp;
    int n,ele;
    cout<<"Enter the size of stack: ";cin>>n;cout<<endl<<"Enter the elements of the stack: ";
    for(int i=1;i<=n;i++)
    {
        cin>>ele;
        s.push(ele);
    }
    cout<<endl;
    int pos;
    cout<<"Enter the position to be inserted: ";cin>>pos;
    for(int i=1;i<pos;i++)
    {
        temp.push(s.top());
        s.pop();
    }
    n++;
    cout<<endl;
    cout<<"Enter the element to be inserted: ";
    int insert;
    cin>>insert;
    s.push(insert);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    cout<<endl;
    cout<<"The stack after insertion is ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}