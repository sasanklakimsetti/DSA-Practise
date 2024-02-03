//TRAVERSAL OF AN ARRAY
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i;
    cout<<"Enter size of an array: ";
    cin>>n;
    if(n>100)
    {
        cout<<"Size limit of array exceeded"<<endl;
    }
    else
    {
        cout<<"Enter the elements of the array: "<<endl;
        for(i=0;i<n;i++)   //taking the input of array
        {
            cin>>a[i];
        }
        cout<<"The array is: ";
        for(i=0;i<n;i++)  //printing the elements of the array
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}