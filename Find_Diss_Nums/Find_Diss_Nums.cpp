#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();

        sort(nums.begin(), nums.end());

        for (int i=0, j=0; i < size; i++, 
            j= nums[j] >= i + 1 ? j : j+1) {
            while (j > 0 && nums[j-1] == nums[j])
                j++;

            if (nums[j] != i + 1) 
                ans.push_back(i + 1);           
        }

        return ans;    
    }
};

int main () {
    Solution solution;
    vector<int> nums = {
        // 4,3,2,7,8,2,3,1
        // 1,1
        1,1,2,2
    };

    for (int elem : solution.findDisappearedNumbers(nums))
        cout << elem << endl;
    return 0;
}