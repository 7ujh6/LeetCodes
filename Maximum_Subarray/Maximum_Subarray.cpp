#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1)
         return nums[0];

        vector<int> sorted_nums = vector<int>(nums);
        sort (sorted_nums.begin(), sorted_nums.end());

        if (sorted_nums[sorted_nums.size() - 1] <= 0)
            return sorted_nums[sorted_nums.size() - 1];


        int max = 0, curr_max = 0;

        for (int i = 0; i < nums.size(); i++) {

            curr_max += nums[i];

            if (curr_max < 0)
                curr_max = 0;
            else 
                max = curr_max > max ? curr_max : max;
        }

        return max;
    }
};

int main () {

    Solution solution;
    vector<int> nums = {
        // 1,2,3,4,-5,5,6,7,8
        // -2,1,-3,4,-1,2,1,-5,4
        // 1
        // 0
        // -1
        // -2147483647
        //-2,-3,4,-1,-2,1,5,-3
        -2,-1
    };

    cout << solution.maxSubArray(nums);
    return 0;
}