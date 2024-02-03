#include <iostream>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate an array by D elements
void rotateArray(int arr[], int N, int D) {
    // Reverse the first D elements
    reverseArray(arr, 0, D - 1);
    
    // Reverse the remaining elements
    reverseArray(arr, D, N - 1);
    
    // Reverse the entire array
    reverseArray(arr, 0, N - 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, D;
        cin >> N >> D;

        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        // Rotate the array by D elements
        rotateArray(arr, N, D);

        // Print the rotated array
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
