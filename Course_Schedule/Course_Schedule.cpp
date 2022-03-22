#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
        bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop(); n--;
            for (auto next: adj[curr])
                if (--degree[next] == 0) q.push(next);
        }
        return n == 0;
    }
};

int main()
{
    Solution solution;
    int numCourses =
        // 2;
        // 3;
        4;
        // 20;

    vector<vector<int>> prerequisites {
        // {1,0}
        // {1, 0},
        // {0, 1}
        // {1,0},{2,1},{3,2}
        {0,1},{0,2},{0,3},{2,3}
        // {0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}
    };

    cout << solution.canFinish(numCourses, prerequisites);
    return 0;
}

/*
    // First Approach

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty())
            return true;

        set<pair<int, int>> restricted;

        for (int i=0; i < prerequisites.size(); i++) {
            bool isConflict = restricted.count({prerequisites[i][0], prerequisites[i][1]});
            if (isConflict)
                return false;
            else 
                restricted.insert({prerequisites[i][1], prerequisites[i][0]});
        }

        return true;
    }

*/