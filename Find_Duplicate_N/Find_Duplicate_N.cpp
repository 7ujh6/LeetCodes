#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise  = nums[0], hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {
        // 3,3
        // 1,2,2,2,3
        // 1,3,3,3,4
        // 1,2,3,3,3
        // 1,2,2,2,4
        // 1,2,4,4,4
        1,3,4,4,4
        // 1,3,4,2,2 // out: 2
        // 3,1,3,4,2 // out: 3
        // 1,1 // out: 1
        // 1,1,2 // out: 1
    };

    cout << solution.findDuplicate(nums);
    return 0;
}

/// First Attempt (works on duplicates of strictly 2)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size()-1, sum = (n*(n+1))/2;

//         for (int i=0;i<nums.size();i++)
//             sum -= nums[i];

//         return -sum;
//         return sum;
//     }
// };