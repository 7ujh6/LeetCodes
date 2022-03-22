#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;
        
        int N = nums.size();
        vector<int> dp(N+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < N; i++) {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[N]; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {
        // 1,2,3,1
        2,7,9,3,1
        // 1,2
        // 3,1
        // 1
        // 
        // 2,1,1,2
    };

    cout << solution.rob(nums);
    return 0;
}