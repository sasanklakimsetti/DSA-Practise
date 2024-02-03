#include<iostream>
using namespace std;
int main()
{
    int s1,s2,s3;
    int a[100],b[100],c[100];
    cout<<"Enter size of arr1: ";
    cin>>s1;
    cout<<"Enter elements of the first array: ";
    for(int i=0;i<s1;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter size of arr2: ";cin>>s2;
    cout<<"Enter elements of arr2: ";
    for(int i=0;i<s2;i++)
    {
        cin>>b[i];
    }
    s3=s1+s2;
    for(int i=0;i<s1;i++)
    {
        c[i] = a[i];
    }
    for(int i=0;i<s2;i++)
    {
        c[s1++]=b[i];
    }
    cout<<"The merged array is ";
    for(int i=0;i<s3;i++)
    {
        cout<<c[i]<<" ";
    }
}