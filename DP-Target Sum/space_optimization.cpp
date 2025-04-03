#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, INT_MAX));

    // Base case: If we use only the first coin
    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
    }

    // Filling the DP table
    for (int indx = 1; indx < n; indx++) {
        for (int t = 0; t <= target; t++) {
            int not_take = dp[indx - 1][t];
            int take = INT_MAX;
            if (coins[indx] <= t) {
                if (dp[indx][t - coins[indx]] != INT_MAX)
                    take = 1 + dp[indx][t - coins[indx]];
            }
            dp[indx][t] = min(not_take, take);
        }
    }

    return (dp[n - 1][target] == INT_MAX) ? -1 : dp[n - 1][target];
}

int main() {
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int target = 11;
    
    int result = coinChange(coins, target);
    
    if (result == -1)
        cout << "Not possible to make the target sum" << endl;
    else
        cout << "Minimum number of coins needed: " << result << endl;

    return 0;
}
