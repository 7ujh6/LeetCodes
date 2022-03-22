#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    // The solution from Leetcode discussions.
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    int k =
    2;
    // 3;
    vector<int> nums = {
        1,1,1
        // 1,2,3
    };

    cout << solution.subarraySum(nums, k) << endl;

    return 0;
}

// 1 1 1 k = 2 count: 2
    
// 1 2 3 // looks like recursion the choice is to include or not to include
//   1 2
//     1
    
//      // The index always increases though in any case
// 1 2 3 k=3 count: 2

// 1 3 6
//   2 5
//     3

// 10 2 -2 -20 10 k = -10 count: 3

// 10 12 10 -10   0
//     2  0 -20 -10 //don't build this branch
//       -2 -22 -12 //build this one
//          -20 -10
//               10
// // What if we have 10 12 -10 0 -10 // k is encountered twice in this branch
// // Is there really no better way / optimization than enumerating every total

    
// 9 4 20 3 10 5 k = 33 count: 2 
//     if (total - branch < k) return // 
//     if (branch == k) return & increment
//     if (sum[i] == k) return & increment
//     if (sum[i] < k ) return

// vector<int> sums = sum[i-1] - nums[i-1]
    
    

// 9 13 33 36 46 51
//    4 24 27 37 42
//      20 23 33 38
//          3 13 18
//            10 15
//                5
    