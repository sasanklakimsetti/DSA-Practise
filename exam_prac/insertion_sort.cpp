#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i,key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void display(int arr[], int n)
{
    cout<<"The sorted array is ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    insertionSort(a,n);
    display(a,n);
    return 0;
}