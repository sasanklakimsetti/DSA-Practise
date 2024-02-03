//DELETION OF ARRAY AT BEGINNING
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(n>100)
    {
        cout<<"Size exceeded"<<endl;
    }
    else
    {
        cout<<"Enter the elements in the array: "<<endl;
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
        for(i=0;i<n;i++)
        {
            a[i]=a[i+1];
        }
        cout<<endl<<"Array after deleting the element at beginning: ";
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}