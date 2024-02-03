#include<iostream>
using namespace std;
int main()
{
    int a[100],n;
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
    n--;
    cout<<"The modified array is ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}