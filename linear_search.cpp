#include<iostream>
using namespace std;

int search(int arr[], int n, int ele) {
    for (int i = 0; i < n; i++) {
        if (ele == arr[i]) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found after iterating through the entire array
}

int main() {
    int a[100], n, i, ele;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << endl << "The array is: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "Enter the element to be searched: ";
    cin >> ele;
    int result = search(a, n, ele);
    if (result == -1) {
        cout << endl << "The element is not present in this array";
    }
    else {
        cout << endl << "The element is present at index: " << result;
    }
}
