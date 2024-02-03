#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int arr[],int size,int target)
{
    int mid,l=0,r=size-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid]<target)
            {
                l=mid+1;
            }
            else if(arr[mid]>target)
            {
                r=mid-1;
            }
        }
        return -1;
}
void bubbleSort(int arr[],int n)
{
    bool swapped;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;
            }
        }
        if(!swapped)
    {
        break;
    }
    }
}
void insertionSort(int a[],int n)
{
    int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;++i)
    {
        int minIndex=i;
        for(int j=i+1;j<n;++j)
        {
            if(a[j]<a[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            swap(a[i],a[minIndex]);
        }
    }
}
int main()
{
    int a[100];
    int n;
    cout<<"Enter size of array: ";cin>>n;
    cout<<endl<<"Enter elements of the array: ";
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<"Enter\n1.Traversal\n2.Insertion at beginning\n3.Insertion at end\n4.Insertion at specific position\n5.Deletion at beginning\n6.Deletion at end\n7.Deletion at specific position\n8.Linear Search\n9.Binary Search\n10.Bubble Sort\n11.Insertion Sort\n12.Selection Sort\n13.Reversal of array";
    int choice;
    cout<<endl<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        //TRAVERSAL OF ARRAY
        cout<<endl<<"The array is ";
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 2:
        //INSERTION AT BEGINNING
        int begin_data;
        cout<<endl<<"Enter the data to be inserted at beginning: ";cin>>begin_data;
        n++;
        
        for(int i=n;i>1;i--)
        {
            a[i-1]=a[i-2];
        }
        a[0]=begin_data;
        cout<<endl<<"The array after insertion: ";
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 3:
        //INSERTION AT END
        int last_data,i;
        cout<<endl<<"Enter the last_data to be inserted at end: ";cin>>last_data;
        n++;
        a[n-1]=last_data;
        cout<<endl<<"The inserted array is ";
        for(i=0;i<n;++i)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 4:
        //INSERTION OF ARRAY AT SPECIFIC POSITION
        int pos,pos_data;
        cout<<endl<<"Enter data to be inserted: ";cin>>pos_data;cout<<endl<<"Enter the position to be inserted: ";cin>>pos;
        
        for(int i=n-1;i>=pos-1;i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=pos_data;
        n++;
        cout<<endl<<"The array after insertion: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 5:
        //DELETION OF AN ARRAY AT BEGINNING
        n--;
        for(int i=0;i<n;i++)
        {
            a[i]=a[i+1];
        }
        cout<<endl<<"The array after deletion at beginning: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 6:
        //DELETION OF ARRAY AT END
        cout<<endl<<"The array after deletion at end: ";
        n--;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 7:
        //DELETION OF ARRAY AT SPECIFIC POSITION
        int del_pos;
        cout<<endl<<"Enter the position to delete: ";
        cin>>del_pos;
        n--;
        for(int i=del_pos;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        cout<<endl<<"The array after deleting at position "<<del_pos<<": ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 8:
        //LINEAR SEARCH
        int search_ele;
        cout<<endl<<"Enter the element to be searched: ";
        cin>>search_ele;
        int search_pos;
        for(int i=0;i<n;i++)
        {
            if(a[i]==search_ele)
            {
                search_pos=i;
            }
        }
        cout<<endl<<"The element "<<search_ele<<" was present in "<<search_pos<<" index and at "<<search_pos+1<<" position.";
        break;
        case 9:
        //BINARY SEARCH
        int target;
        cout<<"Enter element to be searched: ";
        cin>>target;
        int result;
        result=binarySearch(a,n,target);
        if(result!=-1)
        {
            cout<<endl<<"Element found at "<<result<<" index and at "<<result+1<<" position.";
        }
        else
        {
            cout<<endl<<"Element not found.";
        }
        break;
        case 10:
        //BUBBLE SORT
        bubbleSort(a,n);
        cout<<"The array after sorting: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 11:
        //INSERTION SORT
        insertionSort(a,n);
        cout<<endl<<"The array after sorting: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 12:
        //SELECTION SORT
        selectionSort(a,n);
        cout<<endl<<"The array after sorting: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        break;
        case 13:
        //REVERSAL OF ARRAY
        cout<<endl<<"Array after reversing: ";
        for(int i=n-1;i>=0;i--)
        {
            cout<<a[i]<<" ";
        }
        break;
    }
}