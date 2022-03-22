#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                permute(nums, i + 1, perms);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {
        1,2,3
    };

    vector<vector<int>> answer = solution.permute(nums);

    for (vector<int> v : answer) {
        cout << "[";
        for (int elem : v) 
            cout << elem << " ";
        cout << "]"; 
    }

    return 0;
}
