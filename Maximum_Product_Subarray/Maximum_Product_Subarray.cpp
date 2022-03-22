#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//recursive solution
//variable param are the indices: i, j which change to produce different continguous
//products
//global var max contains the max val detected, that way we do not have to store every 
//single generate value in an array or something and then iterate over that to find
//the max value


class Solution {
    int max_prod = 0;
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        maxProduct(nums, 0, 1, nums[0]);
        return max_prod;
    }
    
    void maxProduct (const vector<int>& nums, int i, int j, int contiguous_product) {
        max_prod = max(contiguous_product, max_prod);
        
        for (; i < nums.size() && j < nums.size();) {
            maxProduct(nums, i, j+1, contiguous_product*nums[j]);
            contiguous_product =  ++i < nums.size() ? nums[i] : contiguous_product;
            j = i+1;
            max_prod = max(contiguous_product, max_prod);
        }
    }

};

int main() {
    Solution solution;
    vector<int> nums = {
        // 2,3,-2,4
        // -2,0,-1
        // 0,2
        // 3,-1,4
        // -3,0,1,-2
        0,0,3,3,0,-2,3,-2,-1,-1,2,1
    };

    cout << solution.maxProduct(nums);
    return 0;
}

//Current Method operates int O(n^2) time; Time limit exceeded 
//Alternative method works in O(n) time and uses DP along by keeping the max and min products

