#include <iostream>
#include <vector>

//without bfs
//fails on some inputs

using namespace std;

//maybe an Edge struct, depending on how we want to go about this
//maybe maybe an adjancency list but can also store pairs...
//DP???

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, M = grid.size(), N = grid[0].size();

        if (grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == '1')
            return 1;

        for (int i=0; i < M; i++) {
            for (int j=0; j < N; j++) {
                if (grid[i][j] != '0') {
                    if (grid[i][j] == '1')
                        if (N == 1 || (j+1 < N && grid[i][j+1] != 'T') || (j-1 > 0 && grid[i][j-1] != 'T'))
                            count++;
                    
                    if (i+1 < M && grid[i+1][j] != '0')
                        grid[i+1][j] = 'T';
                    if (j+1 < N && grid[i][j+1] != '0')
                        grid[i][j+1] = 'T';
                    
                }
            }
        }  

        return count; 
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        // {'1','1','1','1','0'},
        // {'1','1','0','1','0'},
        // {'1','1','0','0','0'},
        // {'0','0','0','0','0'}

        // {'1','1','0','0','0'},
        // {'1','1','0','0','0'},
        // {'0','0','1','0','0'},
        // {'0','0','0','1','1'}

        // {'1','1','1',},{'0','1','0'},{'1','1','1'}
        {'1'},{'1'}
    };

    std::cout << solution.numIslands(grid);
    return 0;
}
