#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};



int main() {
    Solution solution;
    vector<int> nums = {
        // 1,5,11,5 // true
        1,2,3,5 // false
    };

    cout << solution.canPartition(nums) << endl;

    return 0;
}

/*
/// First Crack at It
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), total=0;
        for (int i=0; i<N; i++)
            total+=nums[i];
        
        if (total % 2 != 0)
            return 0;
        
        for (int i=0; i<N; i++) {
            for(int j=0;j<N; j++) {
               //total: 22
               // 1 5 11 5
               // 20 17 11 17
               // 15 9 15 : 1
               // 16 6 12 : 5
               // 10 6 6 : 11
               // 16 6 12 : 5
            }
        }
    }

    //sounds like backtracking generate every possible
    //combo check if target - sum = cache[i]

    bool backtrack (vector<int>& nums, vector<int>& cache, int skip) {
        for (int i=0;i<nums.size();i++) {
            //how to keep track of multiple indices to skip
            //one solution is passing a vector copy and swapping 
            //undesirable indices to the back
        }
    }
};


/// Second Crack at It! -- Time Limit Exceeded

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), total=0;
        for (int i=0; i<N; i++)
            total+=nums[i];
        
        if (total % 2 != 0)
            return false;
        unordered_map<string, bool> state;

        return canPartition(nums, 0, 0, total, state);
    }

    bool canPartition(vector<int>& nums, int index, int sum, int total, unordered_map<string, bool>& state) {
        string current = to_string(index) + to_string(sum);
        if (state.count(current)) 
            return state.at(current);
        if (sum * 2 == total)
            return true;
        if (sum > total/2 || index >= nums.size())
            return false;
        bool foundParition = canPartition(nums, index+1, sum, total, state) || 
            canPartition(nums, index+1, sum+nums[index], total, state);
        state.insert({current, foundParition});
        return foundParition;
    }
};

/// DP Solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int half = sum >> 1;
        
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;    // '0' is always reachable
        //For all num in nums, check the accessibility from half - num to 0. 
        //If 'i' is accessible by former numbers, then 'i + num' is also accessible. (DP Algorithm)
        for(auto num : nums) 
       //Below here we must start from 'half' downto 'num', otherwise current 'num' might be multiply used. 
       //e.g.: If num == 2, then we will have 2, 4, 6... will all be accessible and lead to wrong answer. 
            for(int i = half; i >= num; i--){
                if (accessibility[i - num] == true){
                    accessibility[i] = true;
                }
            }
        return accessibility[half];
    }
};



*/