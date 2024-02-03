#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cout<<"Enter size of array: ";cin>>n;
    cout<<"Enter the elements of the array: ";
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
    int val;
    cout<<"Enter the value to be searched in the array: ";cin>>val;
    int pos;
    for(int i=0;i<n;i++)
    {
        if(a[i]==val) 
        {
            pos=i;
            break;
        }
    }
    if(pos!=-1) cout<<"Found at position: "<<pos+1;
    else cout<<"Not found"<<endl;
}