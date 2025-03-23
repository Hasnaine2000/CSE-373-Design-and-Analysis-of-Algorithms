#include <iostream>
using namespace std;

int climbStairs(int indx) {
    if (indx == 0 || indx == 1) return 1; // Base cases

    return climbStairs(indx - 1) + climbStairs(indx - 2);
}

int main() {
    int n = 10; // Change as needed
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
