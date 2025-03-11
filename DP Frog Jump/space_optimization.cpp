#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int minCost(vector<int>& a) {
    int n = a.size();
    int prev2 = 0, prev1 = 0; // Base cases

    for (int i = 1; i < n; i++) {
        int left = prev1 + abs(a[i] - a[i - 1]);
        int right = INT_MAX; // Handle INT_MAX properly

        if (i > 1) {
            right = prev2 + abs(a[i] - a[i - 2]);
        }

        int curr = min(left, right);
        prev2 = prev1; // Move prev1 to prev2
        prev1 = curr;  // Move curr to prev1
    }
    return prev1;
}

int main() {
    vector<int> a = {10, 30, 40, 20}; // Example heights
    cout << "Minimum cost: " << minCost(a) << endl;
    return 0;
}
