#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& heights) {
    int n = heights.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (heights[j] < heights[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(heights[i], heights[minIndex]);
        
        // Display the current state of the heights after each iteration
        for (int k = 0; k < n; k++) {
            cout << heights[k];
            if (k != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n; // Input: Number of students
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i]; // Input: Student heights
    }

    // Output: Unsorted student heights
    for (int i = 0; i < n; i++) {
        cout << heights[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Sorting using selection sort
    selectionSort(heights);
    
    return 0;
}