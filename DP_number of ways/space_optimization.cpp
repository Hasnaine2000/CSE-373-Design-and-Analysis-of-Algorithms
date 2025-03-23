#include <iostream>
using namespace std;

int climbStairs(int indx) {
    if (indx == 0 || indx == 1) return 1; // Base cases

    int prev2 = 1, prev1 = 1;
    
    for (int i = 2; i <= indx; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    int n = 10;
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
