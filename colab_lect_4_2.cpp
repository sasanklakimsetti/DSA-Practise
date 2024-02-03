#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int K;
    cin >> K;
    
    vector<vector<int>> arrays(K);
    
    // Input K sorted arrays
    for (int i = 0; i < K; ++i) {
        int n;
        cin >> n;
        arrays[i].resize(n);
        
        for (int j = 0; j < n; ++j) {
            cin >> arrays[i][j];
        }
    }
    
    priority_queue<int> maxHeap;
    
    // Initialize the max heap with the last elements from each array
    for (int i = 0; i < K; ++i) {
        maxHeap.push(arrays[i].back());
        arrays[i].pop_back();
    }
    
    while (!maxHeap.empty()) {
        int maxValue = maxHeap.top();
        maxHeap.pop();
        
        cout << maxValue << " ";
        
        for (int i = 0; i < K; ++i) {
            if (!arrays[i].empty()) {
                maxHeap.push(arrays[i].back());
                arrays[i].pop_back();
            }
        }
    }
    
    return 0;
}