#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int indx) {
    if (indx == 0 || indx == 1) return 1; // Base cases

    vector<int> dp(indx + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= indx; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[indx];
}

int main() {
    int n = 10;
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
