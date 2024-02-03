#include<iostream>
using namespace std;
#define MAX_SIZE 100
int heap[MAX_SIZE];
int heapSize=0;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void minHeap(int index)
{
    while(index>0&&heap[index]<heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index=(index-1)/2;
    }
}
void insert(int data)
{
    if(heapSize>=MAX_SIZE) cout<<"Heap is full\n";
    else
    {
        heap[heapSize]=data;
        minHeap(heapSize);
        heapSize++;
    }
}
void heapify(int index)
{
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    int largest=index;
    if(leftChild<heapSize && heap[leftChild]<heap[largest]) largest=leftChild;
    else if(rightChild<heapSize&&heap[rightChild]<heap[largest]) largest=rightChild;
    if(largest!=index)
    {
        swap(&heap[index],&heap[largest]);
        heapify(largest);
    }
}
int deletemin()
{
    int deleted=heap[0];
    heap[0]=heap[heapSize-1];
    heapSize--;
    heapify(0);
    return deleted;
}
int main()
{
    int count,i,data;
    cout<<"Enter count: ";cin>>count;
    for(i=0;i<count;i++)
    {
        cout<<"Enter data: ";cin>>data;
        insert(data);
    }
    cout<<"The min heap is ";
    for(i=0;i<heapSize;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    int min=deletemin();
    cout<<"Deleted value: "<<min;
    cout<<"The min heap after deletion is ";
    for(i=0;i<heapSize;i++)
    {
        cout<<heap[i]<<" ";
    }
}