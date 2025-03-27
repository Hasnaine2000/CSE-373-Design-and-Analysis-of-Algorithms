#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, vector<int>& arr) {
    if (n == 0) {
        return arr[0]; // Base case
    }

    // Initialize two variables to store the last two results
    int prev2 = arr[0]; // Base case for dp[0]
    int prev1 = max(arr[0], arr[1]); // Base case for dp[1]

    // Iteratively calculate the result using space optimization
    for (int i = 2; i < n; i++) {
        int current = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1; // The result for the last index
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7}; // Example array
    int n = arr.size();

    // Call the optimized function
    cout << "Maximum sum: " << f(n, arr) << endl;

    return 0;
}
