#include<bits/stdc++.h>
using namespace std;
void maxheapify(int heap[],int n,int i){
    int leftchild=2*i+1;
    int rightchild=2*i+2;
    int largest=i;
    if(leftchild<n && heap[leftchild]>heap[largest]){
        largest=leftchild;
    }
    if(rightchild<n && heap[rightchild]>heap[largest]){
        largest=rightchild;
    }
    if(largest!=i){
        int temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        maxheapify(heap,n,largest);
    }
}
int main(){
    int n,i;
    cout<<"Enter size: ";
    cin>>n;
    int heap[n];
    for(i=0;i<n;i++){
        cin>>heap[i];
    }
    cout<<"original array: ";
    for(i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    for(i=n/2-1;i>=0;i--){
        maxheapify(heap,n,i);
    }
    cout<<"After sorting: ";
    for(i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    cout<<"After heap sort: ";
    for (int i=n-1; i>=0; i--) {
    int temp=heap[0];
    heap[0]=heap[i];
    heap[i]=temp;
    maxheapify(heap,i,0);
  }
    for(i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}