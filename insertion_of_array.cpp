//INSERTION OF AN ARRAY AT SPECIFIC POSITION
#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int n,i;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(n>100)
    {
        cout<<"Size Limit exceeded"<<endl;
    }
    else
    {
        cout<<"Enter the elements of array: "<<endl;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<"The array is: ";
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        int pos;
        char ele;
        cout<<endl<<"Enter the position to be inserted: ";
        cin>>pos;
        cout<<"Enter the element to be inserted: ";
        cin>>ele;
        if((pos<=0)||(pos>(n+1)))
        {
            cout<<"Invalid "<<endl;
        }
        else
        {
            for(i=n-1;i>=pos-1;i--)
            {
                a[i+1]=a[i];
            }
            a[pos-1]=ele;
            n++;
            cout<<"The array after insertion is: ";
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
    }
    return 0;
}