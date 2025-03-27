#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int indx, vector<int>& arr) {
    // Base case: if index is 0, return arr[indx]
    if (indx == 0) {
        return arr[indx];
    }

    // Base case: if index is less than 0, return 0
    if (indx < 0) {
        return 0;
    }

    // Recursive case: choose to either pick or not pick the current element
    int pick = arr[indx] + f(indx - 2, arr);
    int not_pick = 0 + f(indx - 1, arr);

    // Return the maximum of both choices
    return max(pick, not_pick);
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7}; // Example array
    int n = arr.size();
    
    // Call the function for the last index
    cout << "Maximum sum: " << f(n - 1, arr) << endl;

    return 0;
}
