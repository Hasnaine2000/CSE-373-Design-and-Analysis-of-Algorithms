#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, vector<int>& arr) {
    if (n == 0) {
        return arr[0]; // Base case
    }

    // Tabulation array to store results of subproblems
    vector<int> dp(n);

    // Initialize the base cases
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    // Fill the dp array using the bottom-up approach
    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1]; // Return the result for the last index
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7}; // Example array
    int n = arr.size();

    // Call the tabulation function
    cout << "Maximum sum: " << f(n, arr) << endl;

    return 0;
}
