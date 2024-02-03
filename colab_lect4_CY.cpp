#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int sizel, size2;
    cin >> sizel; // Input: Size of the first array
    vector<string> arrl(sizel);
    for (int i = 0; i < sizel; i++) {
        cin >> arrl[i]; // Input: Elements of the first array
    }

    cin >> size2; // Input: Size of the second array
    vector<string> arr2(size2);
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i]; // Input: Elements of the second array
    }

    // Create a set to store unique combinations of strings
    unordered_set<string> uniqueCombinations;

    // Generate all possible unique combinations
    for (const string& str1 : arrl) {
        for (const string& str2 : arr2) {
            uniqueCombinations.insert(str1 + str2);
        }
    }

    // Output: Merged array with unique combinations of strings
    for (const string& combination : uniqueCombinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}