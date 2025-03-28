#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fTabulation(vector<vector<int>> &task) {
    int n = task.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    for (int i = 0; i < 3; i++) {
        dp[0][i] = task[0][i];
    }
    dp[0][3] = max({task[0][0], task[0][1], task[0][2]});
    
    for (int indx = 1; indx < n; indx++) {
        for (int last = 0; last < 4; last++) {
            dp[indx][last] = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    int points = task[indx][i] + dp[indx - 1][i];
                    dp[indx][last] = max(dp[indx][last], points);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int main() {
    vector<vector<int>> task = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    
    cout << "Max points (Tabulation): " << fTabulation(task) << endl;
    
    return 0;
}
