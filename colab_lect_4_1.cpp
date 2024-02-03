#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> firstList;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        firstList.push_back(num);
    }

    int m;
    cin >> m;

    vector<int> secondList;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        secondList.push_back(num);
    }

    vector<int> mergedList;
    mergedList.reserve(n + m);

    mergedList.insert(mergedList.end(), firstList.begin(), firstList.end());
    mergedList.insert(mergedList.end(), secondList.begin(), secondList.end());

    sort(mergedList.begin(), mergedList.end());

    vector<int> firstOutput;
    vector<int> secondOutput;

    int mid = mergedList.size() / 2;
    firstOutput.assign(mergedList.begin(), mergedList.begin() + mid);
    secondOutput.assign(mergedList.begin() + mid, mergedList.end());

    for (int num : firstOutput) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : secondOutput) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}