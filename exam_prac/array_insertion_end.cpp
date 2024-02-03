#include<iostream>
using namespace std;
int main()
{
    int a[100],n,end;
    cout<<"Enter size: ";cin>>n;
    cout<<"Enter elements: ";
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
    cout<<"Enter the element to insert at end: ";cin>>end;
    n++;
    a[n-1]=end;
    cout<<"The modified array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}