#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int f(int indx, vector<int>& a) {
    if (indx == 0) return 0; // Base case

    int left = f(indx - 1, a) + abs(a[indx] - a[indx - 1]);
    int right = INT_MAX;

    if (indx > 1) {
        right = f(indx - 2, a) + abs(a[indx] - a[indx - 2]);
    }

    return min(left, right);
}

int main() {
    vector<int> a = {10, 30, 40, 20}; // Example heights
    int n = a.size();
    cout << "Minimum cost: " << f(n - 1, a) << endl;
    return 0;
}
