//INSERTION OF AN ARRAY AT BEGINNING
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i,ele;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(n>100)
    {
        cout<<"Size exceeded"<<endl;
    }
    else
    {
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
        cout<<"Enter the element to be inserted at the beginning: ";
        cin>>ele;
        n++;
        for(i=n;i>1;i--)
        {
            a[i-1]=a[i-2];
        }
        a[0]=ele;
        cout<<"The resultant array is: ";
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}