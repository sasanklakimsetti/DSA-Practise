#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int l,int r,int x)
{
    while(l<=r)
    {
        int m = l + (r-1)/2;
        if(arr[m]==x) //if mid element is equal to searching element 
        {
            return m;
        }
        else if(arr[m]<x) //if searching element is greater than mid element,ignore left half
        {
            l = m + 1;
        }
        else //if searching element is less than mid element,ignore right half
        {
            r = m - 1;
        }
    }
    return -1;
}
int main()
{
    int a[100],n,i,ele;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<endl<<"Enter the elements of the array: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<"The array is: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Enter the element to be searched: ";
    cin>>ele;
    int result = binarySearch(a,0,n-1,ele);
    if(result==-1)
    {
        cout<<endl<<"The element is not present in the array";
    }
    else
    {
        cout<<endl<<"The element is present at index: "<<result;
    }
}