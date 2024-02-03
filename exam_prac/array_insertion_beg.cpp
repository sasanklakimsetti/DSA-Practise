#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
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
    int beg;
    cout<<"Enter the element to insert at beginning: ";
    cin>>beg;
    n++;
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=beg;
    cout<<"The modified array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}