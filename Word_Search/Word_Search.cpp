#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
    bool exists;
public:
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int, int>> starting_points;
        vector<vector<bool>> visited;
        

        int M = board.size(), N = board[0].size(), index = 0, size = word.size() - 1;
        visited.resize(M, vector<bool>(N, false));

        for (int i=0; i < M; i++) {
            for (int j=0; j < N; j++) {
                if (board[i][j] == word[0])
                    starting_points.push(pair<int, int>(i, j));
            }
        }

        while (!starting_points.empty()) {
            index = 0;
            pair<int, int> curr = starting_points.front();

            trace_path(board, visited, word, curr, index, M, N, size);

            if (exists)
                return true;

            starting_points.pop();   
        }   

        return false;  
    }

    bool trace_path(vector<vector<char>>& board, vector<vector<bool>> visited, string& word, pair<int, int> curr, int index, int M, int N, int size) {

        if (index == size)
            exists = true;

        visited[curr.first][curr.second] = true;

        if (curr.second+1 < N && !visited[curr.first][curr.second+1] && board[curr.first][curr.second+1] == word[index+1])
           trace_path(board, visited, word, pair<int, int>(curr.first, curr.second+1), index+1, M, N, size);
        if (curr.first+1 < M && !visited[curr.first+1][curr.second] && board[curr.first+1][curr.second] == word[index+1])
           trace_path(board, visited, word, pair<int, int>(curr.first+1, curr.second), index+1, M, N, size);
        if (curr.second-1 >= 0 && !visited[curr.first][curr.second-1] && board[curr.first][curr.second-1] == word[index+1])
           trace_path(board, visited, word, pair<int, int>(curr.first, curr.second-1), index+1, M, N, size);
        if (curr.first-1 >= 0 && !visited[curr.first-1][curr.second] && board[curr.first-1][curr.second] == word[index+1])
           trace_path(board, visited, word, pair<int, int>(curr.first-1, curr.second), index+1, M, N, size);

        return false;      
    }
};

int main() {
    Solution solution;
    string word = 
    "SEE";
    // "ABCCED";
    // "ABCB";
    // "ba";
    // "aaaaaaaaaaaaa";

    vector<vector<char>> board = {

        // {'A','B','C','E'},
        // {'S','F','C','S'},
        // {'A','D','E','E'}

        // {'A','B','C','E'},
        // {'S','F','C','S'},
        // {'A','D','E','E'}

        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
        
        // {'a', 'b'}

        // {'a','a','a','a'},
        // {'a','a','a','a'},
        // {'a','a','a','a'}
    };


    std::cout << solution.exist(board, word);

    return 0;
}