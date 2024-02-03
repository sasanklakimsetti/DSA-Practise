#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }

        // Print the current height order
        for (int k = 0; k < n; ++k) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    int heights[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }

    std::cout << "Student's height order before sorting:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << heights[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(heights, n);

    std::cout << "Height order of students after sorting:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << heights[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}