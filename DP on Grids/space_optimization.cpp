#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    vector<int> prev(n, 1);  // Previous row initialized to 1

    for (int i = 1; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            int up = prev[j];
            int left = (j > 0) ? curr[j - 1] : 0;
            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main() {
    int m = 3, n = 3;
    cout << "Number of paths: " << uniquePaths(m, n) << endl;
    return 0;
}
