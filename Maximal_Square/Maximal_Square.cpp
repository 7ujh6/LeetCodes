#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};

int main () {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} // out: 4
        // {'0','1'},{'1','0'} // out: 1
        // {'0'} // out: 0
        // {{'0','1'}}
        // {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}
        // {{'1','1'},{'1','1'}}
        // {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}}
    };

    cout << solution.maximalSquare(matrix);
    return 0;
}


//Second Attempt (mutating the input array changes the final answer in some   cases)
/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int area = 1, count = 0;

        for (int i=0,k=0; i<M; i++) {
            for (int j=0; j<N; j++,k++) {
                int left=j-0, up=i-0, diag=i-0&&j-0&&matrix[i-1][j-1]-'0';
                count+=matrix[i][j]-'0';

                if (left && diag && up) {
                    left=matrix[i][j-1]-'0', up=matrix[i-1][j]-'0';

                    if (left && up && (left >= up || up >= left)) {
                        int update =  min(left, up) + 1;
                        matrix[i][j] = '0' + update;
                        area = max(area, update);
                    }            
                }
            }
        }
        
        return count ? pow(area, 2) : count;
    }
};

*/
// First Attempt
/*
int maximalSquare(vector<vector<char>>& matrix) {
        vector<unordered_set<string>> row_format(matrix.size());
        int area = pow(min(matrix.size(), matrix[0].size()), 2);
        int count = 0; //making sure there is at least 1 zero;

        for (int i=0; i < matrix.size(); i++) {
            string insert = "";
            for (int j=0; j < matrix[i].size(); j++) {
                insert+=matrix[i][j];
                row_format[i].insert(insert);
                count += matrix[i][j] - '0';
            }
        }

        if (!count) //no ones encountered
            return count;

        while (area !=  1) {
            int N = pow(area, .5);
            bool contains = true; //this row has N # of 1's
            int count = 0, start = 0, end = 0;
            vector<pair<int, int>> ranges;

            string row = string(N--, '1');

            for (int i=0; i < matrix.size(); i++) {
                if (row_format[i].count(row)) {
                    count++, end++;

                    if (count == N) {
                        ranges.push_back({start++, end});
                    } 
                } else 
                    start=i+1, end=i+1, count=0;
            }

            //double checking (the big part)
            if (!ranges.empty()) { //if every row contains N # of 1's
                for (pair<int, int> range : ranges) {
                    string position_string;
                    int start; //Impossible???
                    //This solution is suboptimal (most likely)

                    for(int i=range.first;i<range.second;i++) {
                        if () {
                            return area;
                        } 
                    }
                }
            }
            area = pow(N, 2);
        }
        //Assume the biggest --> min: min(m,n) --> min x min area
        //Check if each row satisfies this assumption
        //return the maximal area
        return area;
    }
*/