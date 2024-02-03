#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;

    std::vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }

    std::cin >> m;

    std::vector<int> arr2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> arr2[i];
    }

    // Calculate the sum of merged arrays' negative values
    for (int i = 0; i < std::min(n, m); ++i) {
        std::cout << -arr1[i] - arr2[i] << " ";
    }
    
    // Print the remaining elements of the longer array
    for (int i = std::min(n, m); i < std::max(n, m); ++i) {
        if (n > m) {
            std::cout << -arr1[i] << " ";
        } else {
            std::cout << -arr2[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}