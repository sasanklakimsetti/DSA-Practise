#include<iostream>
using namespace std;
void binarySearch(int arr[], int n, int v)
{
    int l=0;
    int h=n-1;
    while (l<=h)
    {
        int mid = l+(h-l)/2;
        if(arr[mid]==v)
        {
            cout<<"Found at position: "<<mid+1;
            return;
        }
        else if(arr[mid]<v) 
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    cout<<"Element not found"<<endl;
}
int main()
{
    int n,a[100],val;
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
    cout<<"enter value to be searched: ";
    cin>>val;
    binarySearch(a,n,val);
}