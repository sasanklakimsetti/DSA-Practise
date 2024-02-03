#include<bits/stdc++.h>
using namespace std;
#define MAX_HEAP_SIZE 100
int heap[MAX_HEAP_SIZE];
int heapSize=0;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxHeap(int index){
    while(index>0 && heap[index]>heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index=(index-1)/2;
    }
}
void insert(int value){
    if(heapSize>=MAX_HEAP_SIZE){
        cout<<"Heap is full.cannot insert"<<endl;
        return;
    }
    heap[heapSize]=value;
    maxHeap(heapSize);
    heapSize++;
}
void heapify(int index){
    int leftchild=2*index+1;
    int rightchild=2*index+2;
    int largest=index;
    if(leftchild<heapSize && heap[leftchild]>heap[largest]){
        largest=leftchild;
    }
    if(rightchild<heapSize && heap[rightchild]>heap[largest]){
        largest=rightchild;
    }
    if(largest!=index){
        swap(&heap[index],&heap[largest]);
        heapify(largest);
    }
}
int deleteMax(){
    if(heapSize==0){
        cout<<"Heap is empty.cannot delete.";
        return -1;
    }
    int deletedValue=heap[0];
    heap[0]=heap[heapSize-1];
    heapSize--;
    heapify(0);
    return deletedValue;
}
int main(){
    int count,i,data;
    cout<<"Enter Count: ";
    cin>>count;
    for(i=0;i<count;i++){
        cout<<"Enter data: ";
        cin>>data;
        insert(data);
    }
    cout<<"Max heap after insertion: ";
    for(i=0;i<heapSize;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    int max=deleteMax();
    cout<<"Deleted Max element: "<<max;
    cout<<endl;
    cout<<"Max heap after deletion: ";
    for(i=0;i<heapSize;i++){
        //for(i=heapSize-1;i>=0;i--){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return 0;
}