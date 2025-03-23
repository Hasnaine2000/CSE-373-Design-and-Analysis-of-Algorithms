#include <iostream>
#include <vector>
using namespace std;

int climbStairsHelper(int indx, vector<int>& memo) {
    if (indx == 0 || indx == 1) return 1; // Base cases
    if (memo[indx] != -1) return memo[indx]; // Check if already computed

    memo[indx] = climbStairsHelper(indx - 1, memo) + climbStairsHelper(indx - 2, memo);
    return memo[indx];
}

int climbStairs(int indx) {
    vector<int> memo(indx + 1, -1); // Initialize memoization table
    return climbStairsHelper(indx, memo);
}

int main() {
    int n = 10;
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
