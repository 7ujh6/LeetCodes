#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    /// Brute Force Approach (Memo)
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return backtrack(nums, memo, target, 0, 0);
    
    }

    int backtrack(vector<int>& nums, unordered_map<string, int>& memo, int target, int index, int sum) {

        string key = to_string(index)+"_"+to_string(sum);
        if(memo.count(key))
            return memo.at(key);
        if (index >= nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        int ans = backtrack(nums, memo, target, index+1, sum+nums[index]) + 
            backtrack(nums, memo, target, index+1, sum-nums[index]);
        
        memo.insert({key, ans});
        return ans;
        
    }
};

// backtracking? winner winner chicken dinner

int main() {
    Solution solution;
    int target =
    3;
    // 1;
    vector<int> nums = {
        1,1,1,1,1
        // 1
    };

    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;   
}


/* 
/// Outputs
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Input: nums = [1], target = 1
Output: 1
*/


/*
/// Brute Force Approach; 0(2n)
class Solution {
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
    
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum) {

        if (index >= nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }
        
        backtrack(nums, target, index+1, sum+nums[index]);
        backtrack(nums, target, index+1, sum-nums[index]);
    }
};

*/

/*
/// For Debugging
class Solution {
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        string debug = "";
        backtrack(nums, target, 0, 0, debug);
    
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum, string debug) {

        if (index >= nums.size()) {
            if (sum == target) {
                // cout << debug << endl;
                count++;
            }
            return;
        }
        
        // cout << index << "," << sum << endl;
        string debug_minus = debug + "-" + to_string(nums[index]);
        string debug_plus = debug + "+" + to_string(nums[index]);

        backtrack(nums, target, index+1, sum+nums[index], debug_plus);
        backtrack(nums, target, index+1, sum-nums[index], debug_minus);
    }
};

// backtracking? winner winner chicken dinner

int main() {
    Solution solution;
    int target =
    3;
    // 1;
    vector<int> nums = {
        1,1,1,1,1
        // 1
    };

    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;   
}

*/