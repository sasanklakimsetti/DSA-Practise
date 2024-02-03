#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            cout<<a[i];
        }
    }
}