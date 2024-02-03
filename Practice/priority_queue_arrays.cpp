//IMPLEMENTATION OF A PRIORITY QUEUE USING AN ARRAY ASSUMING THAT THE HIGHEST NUMBER HAS HIGHEST PRIORITY
#include<iostream>
#include<queue>
using namespace std;
int a[1024];
int main()
{
    int n;
    cout<<"Enter the size of the queue: ";cin>>n;
    cout<<endl;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    priority_queue<int>p; //declaration of priority queue
    //pushing the array into priority queue
    for(int i=0;i<n;i++)
    {
        p.push(a[i]);
    }
    //printing priority queue
    cout<<endl;
    cout<<"The priority queue is ";
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
}