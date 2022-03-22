#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = 1;

        for (; index < nums.size() && nums[index] > nums[index-1]; index++);

        int right = binarySearch(nums, 0, index-1, target);
        return right != -1 ? right : binarySearch(nums, index, nums.size()-1, target);

    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {

        if (r >= l) {
            int mid = l + (r-l) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                return binarySearch(nums, l, mid-1, target);

            return binarySearch(nums, mid+1, r, target);
        }

        return -1;
    }
};

int main() {
    Solution solution;
    int target = 0;
    vector<int> nums = {
        4,5,6,7,0,1,2
    };

    cout << solution.search(nums, target);

    return 0;
}