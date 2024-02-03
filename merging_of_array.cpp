//MERGING OF ARRAY WITH AND WITHOUT SORTING
#include<iostream>
using namespace std;
int main()
{
    int a1[100],a2[100],a3[100],n1,n2,n3,i,j;
    cout<<"Enter the size of first array: ";
    cin>>n1;
    cout<<endl<<"Enter the size of second array: ";
    cin>>n2;
    n3=n1+n2;
    cout<<endl<<"Enter the elements of first array: ";
    for(i=0;i<n1;i++)
    {
        cin>>a1[i];
        a3[i]=a1[i];
    }
    int k=n1;
    cout<<endl<<"Enter the elements of second array: ";
    for(i=0;i<n2;i++)
    {
        cin>>a2[i];
        a3[k]=a2[i];
        k++;
    }
    cout<<endl<<"Merged array before sorting: ";
    for(i=0;i<n3;i++)
    {
        cout<<a3[i]<<" ";
    }
    for(i=0;i<n3;i++)
    {
        int temp;
        for(j=i+1;j<n3;j++)
        {
            if(a3[i]>a3[j])
            {
                temp=a3[i];
                a3[i]=a3[j];
                a3[j]=temp;
            }
        }
    }
    cout<<endl<<"Merged array after sorting: ";
    for(i=0;i<n3;i++)
    {
        cout<<a3[i]<<" ";
    }
}