//INSERTION OF AN ARRAY AT END
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
        cout<<endl<<"Enter the element to be inserted at the end: ";
        n++;
        cin>>ele;
        a[i]=ele;
        cout<<"The resultant array is: ";
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
   }
   return 0;
}