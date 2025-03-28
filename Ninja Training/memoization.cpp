#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fMemo(int indx, int last, vector<vector<int>> &task, vector<vector<int>> &dp) {
    if (indx == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, task[0][i]);
            }
        }
        return maxi;
    }
    
    if (dp[indx][last] != -1) return dp[indx][last];
    
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int points = fMemo(indx - 1, i, task, dp) + task[indx][i];
            maxi = max(maxi, points);
        }
    }
    return dp[indx][last] = maxi;
}

int main() {
    vector<vector<int>> task = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    int n = task.size();
    
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << "Max points (Memoization): " << fMemo(n - 1, 3, task, dp) << endl;
    
    return 0;
}
