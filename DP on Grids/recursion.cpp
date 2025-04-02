#include <iostream>

int f(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    
    int up = f(i - 1, j);
    int left = f(i, j - 1);
    
    return up + left;
}

int main() {
    int i = 2, j = 2; // Example input
    std::cout << "Number of paths: " << f(i, j) << std::endl;
    return 0;
}

//min sum problems will be similar to this but just add " up = a[i][j] + f(i - 1, j);  and return the min of up and left 
//if the problem contains obstancles then just check if the cell is not an obstacle before calling the function and base case if (i < 0 || j < 0) return INT_MAX;