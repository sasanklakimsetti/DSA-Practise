#include<iostream>
using namespace std;
int main()
{
    int n,a[100],pos;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    cin>>pos;
    int val;
    for(int i=0;i<n;i++)
    {
        if(i==pos) 
        {
            val=a[i-1];
            break;
        }
    }
    cout<<val<<endl;
}