#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compareEnvelopes(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if (n <= 1) {
        return n;
    }    
    sort(envelopes.begin(), envelopes.end(), compareEnvelopes);
    vector<int> dp(n, 1);
    int maxCount = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxCount = max(maxCount, dp[i]);
    }
    
    return maxCount;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> envelopes(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }
    int result = maxEnvelopes(envelopes);
    cout << result << endl;
    return 0;
}