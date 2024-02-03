#include<iostream>
using namespace std;
int main()
{
    int a[100],n,pos;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter position to delete: ";cin>>pos;
    for(int i=pos-1;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    cout<<"The modified array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}