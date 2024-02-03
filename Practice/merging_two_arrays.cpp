//MERGING OF TWO ARRAY ALONG WITH SORTNG
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3;
    cout<<"Enter size of first array: ";cin>>n1;cout<<endl<<"Enter size of second array: ";cin>>n2;
    int a[100],b[100],c[100];
    cout<<endl<<"Enter the elements of first array: ";
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    n3=n1;
    cout<<endl<<"Enter the elements of the second array: ";
    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
        c[n3]=b[i];
        n3++;
    }
    cout<<endl<<"The array after merging before sorting: ";
    for(int i=0;i<n3;i++)
    {
        cout<<c[i]<<" ";
    }
    for(int i=0;i<n3-1;i++)
    {
        for(int j=0;j<n3-i-1;j++)
        {
            int temp;
            if(c[j]>c[j+1])
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    cout<<endl<<"The merged array after sorting: ";
    for(int i=0;i<n3;i++)
    {
        cout<<c[i]<<" ";
    }
}