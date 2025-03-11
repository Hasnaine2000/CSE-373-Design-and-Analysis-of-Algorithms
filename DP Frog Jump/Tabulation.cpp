#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int minCost(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 0);

    dp[0] = 0; // Base case
    for (int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(a[i] - a[i - 1]);
        int right = INT_MAX; // Handle INT_MAX properly

        if (i > 1) {
            right = dp[i - 2] + abs(a[i] - a[i - 2]);
        }

        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

int main() {
    vector<int> a = {10, 30, 40, 20}; // Example heights
    cout << "Minimum cost: " << minCost(a) << endl;
    return 0;
}
