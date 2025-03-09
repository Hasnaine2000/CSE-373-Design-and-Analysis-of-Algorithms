#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    vector<int> dp(n + 1, 0); // Initialize dp array with 0
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    
    return 0;
}
