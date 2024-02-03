#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int n, m;
    cin >> n;
    
    int array1[MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        cin >> array1[i];
    }
    
    cin >> m;
    
    int array2[MAX_SIZE];
    for (int i = 0; i < m; ++i) {
        cin >> array2[i];
    }
    
    int mergedArray[MAX_SIZE * 2]; // The merged array can have at most n + m elements
    
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }
    
    while (i < n) {
        mergedArray[k++] = array1[i++];
    }
    
    while (j < m) {
        mergedArray[k++] = array2[j++];
    }
    
    int minElement = mergedArray[0];
    for (int i = 1; i < k; ++i) {
        if (mergedArray[i] < minElement) {
            minElement = mergedArray[i];
        }
    }
    
    cout << minElement << endl;

    return 0;
}