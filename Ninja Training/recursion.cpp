#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int indx, int last, vector<vector<int>> &task) {
    if (indx == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, task[0][i]);
            }
        }
        return maxi;
    }
    
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int points = f(indx - 1, i, task) + task[indx][i];
            maxi = max(maxi, points);
        }
    }
    return maxi;
}

int main() {
    vector<vector<int>> task = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    int n = task.size();
    cout << "Max points (Recursive): " << f(n - 1, 3, task) << endl;
    return 0;
}
