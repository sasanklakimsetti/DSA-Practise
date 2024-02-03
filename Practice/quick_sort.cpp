#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[],int low, int high)
{
    int pivot=arr[high]; //selecting rightmost element as pivot
    int i=(low-1); //pointer for greater element
    for(int j=low;j<high;j++)
    {
        //if element smaller than pivot is found, swap it with the greater element pointed by i
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);  //swap element at i with element at j
        }
    }
    swap(&arr[i+1],&arr[high]);  //swap pivot with greater element at i
    return (i+1); //return partition pointer
}
void quickSort(int arr[],int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);  //recursive call on left of the pivot
        quickSort(arr,pi+1,high);  //recursive call on right of the pivot
    }
}
int main()
{
    int arr[1024];
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array before sorting: ";
    printArray(arr,size);
    quickSort(arr,0,size-1);
    cout<<endl<<"Array after sorting: ";
    printArray(arr,size);
}