#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"The array is ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"The sorted array is ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}