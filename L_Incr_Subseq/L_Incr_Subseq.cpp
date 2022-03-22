#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {
        10,9,2,5,3,7,101,18
        // 0,1,0,3,2,3
        // 7,7,7,7,7,7,7
    };

    cout << solution.lengthOfLIS(nums);
    
    return 0;
}