#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int recursion(int indx) {
    if (indx <= 1) return indx;
    if (dp[indx] != -1) return dp[indx];

    dp[indx] = recursion(indx - 1) + recursion(indx - 2);
    return dp[indx];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    dp.assign(n + 1, -1); // Initialize DP array with -1
    cout << "Fibonacci(" << n << ") = " << recursion(n) << endl;

    return 0;
}
