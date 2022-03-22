#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int N = nums.size()-1;
      
        for (int i=0; i<N; i++) {
            ans[i] = i != 0 ? nums[i] * ans[i-1] :
                nums[i];
        }

        for (int i=N; i>=0; i--) {
            nums[i] = N==i ? nums[i] : nums[i] * nums[i+1];
            if (i==0)
                ans[i] = nums[i+1];
            else if (i==N)
                ans[i] = ans[i-1];
            else
                ans[i] = ans[i-1] * nums[i+1];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {
        1,2,3,4
        // -1,1,0,-3,3
        // 2,3,5,0
    };

    vector<int> answer = solution.productExceptSelf(nums);

    for(int elem : answer)
        cout << elem;
    cout << endl;

    return 0;
}