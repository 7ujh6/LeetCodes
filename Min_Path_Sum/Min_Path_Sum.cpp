#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int from, to, cost;

    Edge(int from, int to, int cost)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }

    Edge(int from, int to)
    {
        this->from = from;
        this->to = to;
    }

    bool operator== (const Edge& edge) const
    {
        return this->from == edge.from && this->to == edge.to;
    }

};

struct Edge_Compare
{
    bool operator() (const Edge& e1, const Edge& e2)
    {
        return e1.cost > e2.cost;
    }
};

vector<vector<Edge>> generate_adj_list(vector<vector<int>> matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<Edge>> adj_list(n*m);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mapped_index = i*m + j;
            if (m > 1) {
                if (j == 0) 
                    adj_list[i*m + j].push_back(Edge(i*m + j, i*m + (j+1), matrix[i][j+1]));
                else if (j == m - 1) 
                    adj_list[i*m + j].push_back(Edge(i*m + j, i*m + (j-1), matrix[i][j-1]));
                else {
                    adj_list[i*m + j].push_back(Edge(i*m + j, i*m + (j-1), matrix[i][j-1]));
                    adj_list[i*m + j].push_back(Edge(i*m + j, i*m + (j+1), matrix[i][j+1]));
                }
            }

            if (n > 1) {
                if (i == 0) 
                    adj_list[i*m + j].push_back((Edge(i*m + j, (i+1)*m + j, matrix[i+1][j])));
                else if (i == n - 1) 
                    adj_list[i*m + j].push_back(Edge(i*m + j, (i-1)*m + j, matrix[i-1][j]));
                else {
                    adj_list[i*m + j].push_back(Edge(i*m + j, (i-1)*m + j, matrix[i-1][j]));
                    adj_list[i*m + j].push_back(Edge(i*m + j, (i+1)*m + j, matrix[i+1][j]));
                }
            }
        }
    }

    return adj_list;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<Edge>> adj_list = generate_adj_list(grid);
        int n = grid.size(), m = grid[0].size();
        vector<bool> visited(n*m);
        vector<int> best_distances(n*m, numeric_limits<int>::max());
        priority_queue<Edge, vector<Edge>, Edge_Compare> next_to_explore;

        best_distances[0] = 0;

        for (Edge edge: adj_list[0]) {
            next_to_explore.push(Edge(edge.to, -1, edge.cost));
            best_distances[edge.to] = edge.cost;
        }

        while (!next_to_explore.empty()) {
            Edge next_most_promising = next_to_explore.top();
            next_to_explore.pop();

            for (Edge edge: adj_list[next_most_promising.from]) {
                if (!visited[edge.to]) {
                    int new_distance = best_distances[edge.from] + edge.cost;

                    if (new_distance < best_distances[edge.to]) {
                        best_distances[edge.to] = new_distance;
                        next_to_explore.push(Edge(edge.to, -1, new_distance));
                    }
                }
            }
        }
        return best_distances[n*m - 1] + grid[0][0];
    }
};

int main() {

    Solution solution;
    vector<vector<int>> grid = {
        // {1,3,1},{1,5,1},{4,2,1}
        // {1,2,3},{4,8,2},{1,5,3}
        // {0}
        // {9,1,4,8}
        // {{5,4,2,9,6,0,3,5,1,4,9,8,4,9,7,5,1},{3,4,9,2,9,9,0,9,7,9,4,7,8,4,4,5,8},{6,1,8,9,8,0,3,7,0,9,8,7,4,9,2,0,1},{4,0,0,5,1,7,4,7,6,4,1,0,1,0,6,2,8},{7,2,0,2,9,3,4,7,0,8,9,5,9,0,1,1,0},{8,2,9,4,9,7,9,3,7,0,3,6,5,3,5,9,6},{8,9,9,2,6,1,2,5,8,3,7,0,4,9,8,8,8},{5,8,5,4,1,5,6,6,3,3,1,8,3,9,6,4,8},{0,2,2,3,0,2,6,7,2,3,7,3,1,5,8,1,3},{4,4,0,2,0,3,8,4,1,3,3,0,7,4,2,9,8},{5,9,0,4,7,5,7,6,0,8,3,0,0,6,6,6,8},{0,7,1,8,3,5,1,8,7,0,2,9,2,2,7,1,5},{1,0,0,0,6,2,0,0,2,2,8,0,9,7,0,8,0},{1,1,7,2,9,6,5,4,8,7,8,5,0,3,8,1,5},{8,9,7,8,1,1,3,0,1,2,9,4,0,1,5,3,1},{9,2,7,4,8,7,3,9,2,4,2,2,7,8,2,6,7},{3,8,1,6,0,4,8,9,8,0,2,5,3,5,5,7,5},{1,8,2,5,7,7,1,9,9,8,9,2,4,9,5,4,0},{3,4,4,1,5,3,3,8,8,6,3,5,3,8,7,1,3}}
        {1,3,5},{2,1,2},{4,3,1}
    };

    cout << solution.minPathSum(grid);



    return 0;
}