#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int f(int indx, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (indx == 0) {
        if (target % coins[0] == 0)
            return target / coins[0];
        else
            return INT_MAX;
    }
    
    if (dp[indx][target] != -1) 
        return dp[indx][target];

    int not_take = f(indx - 1, target, coins, dp);
    int take = INT_MAX;

    if (coins[indx] <= target) {
        int res = f(indx, target - coins[indx], coins, dp);
        if (res != INT_MAX)
            take = 1 + res;
    }

    return dp[indx][target] = min(not_take, take);
}

int main() {
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int target = 11;
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    
    int result = f(n - 1, target, coins, dp);

    if (result == INT_MAX)
        cout << "Not possible to make the target sum" << endl;
    else
        cout << "Minimum number of coins needed: " << result << endl;

    return 0;
}
