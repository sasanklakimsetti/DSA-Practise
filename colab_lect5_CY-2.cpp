#include <iostream>
using namespace std;

int findSmallestMissing(int arr[], int n, int x) {
  // Initialize the left and right pointers
  int low = 0;
  int high = n - 1;

  // Loop until the pointers meet or cross
  while (low <= high) {
    // Find the middle element
    int mid = (low + high) / 2;

    // If the middle element is greater than or equal to x, then the smallest
    // missing positive integer greater than x is the next element after mid
    if (arr[mid] >= x) {
      return mid + 1;
    }

    // Otherwise, the smallest missing positive integer greater than x is in the
    // left half of the array
    else {
      low = mid + 1;
    }
  }

  // If the pointers meet, then all elements in the array are less than or equal
  // to x, so the smallest missing positive integer greater than x is x + 1
  return x + 1;
}

int main() {
  // Read the number of elements in the array
  int n;
  cin >> n;

  // Read the array elements
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Read the value of x
  int x;
  cin >> x;

  // Find the smallest missing positive integer greater than x
  int smallestMissing = findSmallestMissing(arr, n, x);

  // Print the smallest missing positive integer
  cout << "The smallest missing positive integer greater than " << x << " is " << smallestMissing << endl;

  return 0;
}