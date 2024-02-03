#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    cout<<"Enter size: ";cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}