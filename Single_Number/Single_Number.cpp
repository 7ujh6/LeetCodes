#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i%2==0 && i+1 < nums.size()) {
                if (nums[i+1] != nums[i])
                    return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};

int main () {
    Solution solution;
    vector<int> nums = {
        // 2,2,1
        //  4,1,2,1,2
        1
    };
    
    cout << solution.singleNumber(nums);
    return 0;
}