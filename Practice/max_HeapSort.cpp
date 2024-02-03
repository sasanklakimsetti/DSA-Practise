#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxHeapify(int heap[],int n,int i)
{
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    int largest=i;
    if(leftChild<n&&heap[largest]>heap[leftChild]) largest=leftChild;
    else if(rightChild<n&&heap[largest]>heap[rightChild]) largest=rightChild;
    if(largest!=i)
    {
        swap(&heap[i],&heap[largest]);
        maxHeapify(heap,n,largest);
    }
}
int main()
{
    int n,i;
    cout<<"Enter size: ";cin>>n;
    int heap[n];
    for(i=0;i<n;i++)
    {
        cin>>heap[i];
    }
    cout<<"The heap before sorting: ";
    for(i=0;i<n;i++)
    {
        cout<<heap[i]<<" ";
    }
    for(int i=n/2-1;i>=0;i--)
    {
        maxHeapify(heap,n,i);
    }
    cout<<endl;
    cout<<"After sorting: ";
    for(i=0;i<n;i++)
    {
        cout<<heap[i]<<" ";
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&heap[i],&heap[0]);
        maxHeapify(heap,i,0);
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<heap[i]<<" ";
    }
}