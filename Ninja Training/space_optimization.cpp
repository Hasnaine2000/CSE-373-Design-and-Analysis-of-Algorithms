#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fSpaceOptimized(vector<vector<int>> &task) {
    int n = task.size();
    vector<int> prev(4, 0);
    
    for (int i = 0; i < 3; i++) {
        prev[i] = task[0][i];
    }
    prev[3] = max({task[0][0], task[0][1], task[0][2]});
    
    for (int indx = 1; indx < n; indx++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            curr[last] = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    int points = task[indx][i] + prev[i];
                    curr[last] = max(curr[last], points);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}

int main() {
    vector<vector<int>> task = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    
    cout << "Max points (Space Optimized): " << fSpaceOptimized(task) << endl;
    
    return 0;
}
