#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 || j==0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        
    }
};

int main () {
    Solution solution;
    int m = 3, n = 7;

    cout << solution.uniquePaths(m, n);

    return 0;
}