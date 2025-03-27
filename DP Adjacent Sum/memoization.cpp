#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int indx, vector<int>& arr, vector<int>& dp) {
    if (indx == 0) {
        return arr[indx]; // Base case
    }
    if (indx < 0) {
        return 0; // Base case
    }

    // Check if the result is already calculated
    if (dp[indx] != -1) {
        return dp[indx];
    }

    // Recursive case with memoization
    int pick = arr[indx] + f(indx - 2, arr, dp);
    int not_pick = f(indx - 1, arr, dp);

    // Store the result and return
    dp[indx] = max(pick, not_pick);
    return dp[indx];
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7}; // Example array
    int n = arr.size();
    
    // Create a dp vector initialized with -1 (indicating uncomputed results)
    vector<int> dp(n, -1);

    // Call the memoization function for the last index
    cout << "Maximum sum: " << f(n - 1, arr, dp) << endl;

    return 0;
}
