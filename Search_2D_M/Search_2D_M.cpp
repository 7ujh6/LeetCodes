#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0,j=matrix[0].size()-1;i<matrix.size()&&j>=0;) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    int target =
    // 5;
    // 20;
    // 16;
    // 30;
    18;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
    };

    cout << solution.searchMatrix(matrix, target);

    return 0;
}


/*
// Time Limit Exceeded
First Solution:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        queue<Pair> next;
        int M = matrix.size(), N = matrix[0].size();
        next.push({0,0});

        //DFS
        while (!next.empty()) {
            int i = next.front().first, j = next.front().second;
            next.pop();

            if(matrix[i][j]==target) 
                return true;
            else {
                if (j+1-N && matrix[i][j+1]<=target)
                    next.push({i,j+1});
                if (i+1-M && matrix[i+1][j]<=target)
                    next.push({i+1,j});
                if (j && matrix[i][j-1]<=target)
                    next.push({i,j-1});
                if (i && matrix[i-1][j]<=target)
                    next.push({i-1, j});
            }

            matrix[i][j] = numeric_limits<int>::max();
        }
        
        return false;
    }
*/