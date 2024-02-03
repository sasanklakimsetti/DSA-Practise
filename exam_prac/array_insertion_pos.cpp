#include<iostream>
using namespace std;
int main()
{
    int n,a[100],pos,val;
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
    cout<<"Enter the position to be inserted: ";cin>>pos;
    cout<<"Enter the value to be inserted: ";cin>>val;
    n++;
    for(int i=n-2;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    cout<<endl<<"The modified array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}