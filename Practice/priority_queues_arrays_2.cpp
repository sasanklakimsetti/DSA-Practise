//IMPLEMENTATION OF PRIORITY QUEUE USING AN ARRAY ASSUMING THAT THE LOWEST VALUE HAS HIGHEST PRIORITY
#include<iostream>
#include<queue>
using namespace std;
int a[1024];
int main()
{
    int n;
    cout<<"Enter the size of queue: ";cin>>n;cout<<endl;
    cout<<"Enter the elements of the queue: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>>p; //A std::priority_queue named p is declared. It's declared as a min-heap (lowest element at the top) using a custom comparison function (greater<int>). The vector<int> specifies the underlying container type for the priority queue.  This is like a min-heap
    for(int i=0;i<n;i++)
    {
        p.push(a[i]);
    }
    cout<<endl;
    cout<<"The priority queue is ";
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}