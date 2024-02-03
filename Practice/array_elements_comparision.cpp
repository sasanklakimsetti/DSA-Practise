#include<iostream>
using namespace std;
int main()
{
    int arr1[],arr2[];
    int size1,size2;
    cout<<"Enter size of array 1: ";
    cin>>size1;
    cout<<"Enter elements of array 1: ";
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter size of array 2: ";cin>>size2;
    cout<<"Enter elements of array 2: ";
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }
    for(int i=0;i<size1&&i<size2;i++)
}