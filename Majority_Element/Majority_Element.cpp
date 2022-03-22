#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];

        unordered_map<int, int> tally;
        int majority = nums.size() / 2;

        for (int i=0; i < nums.size(); i++) {
            if (!tally.insert(pair<int, int>(nums[i], 1)).second) {
                if (++tally.at(nums[i]) > majority)
                    return nums[i];
            }
        }

        return -1;
    }
};

int main () {
    Solution solution;
    vector <int> nums = {
        3,2,3
        // 2,2,1,1,1,2,2
    };

    cout << solution.majorityElement(nums);

    return 0;
}