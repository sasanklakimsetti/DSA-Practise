//DELETION OF ELEMENT OF AN ARRAY AT END
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i;
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter the elements of the array: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The array is: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    n--;
    cout<<endl<<"The array after deletion: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}