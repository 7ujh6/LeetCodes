#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();

        // Count the zeroes
        int numZeroes = 0;
        for (int i = 0; i < n; i++)
        {
            numZeroes += (nums[i] == 0);
        }

        // Make all the non-zero elements retain their original order.
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // Move all zeroes to the end
        while (numZeroes--)
        {
            ans.push_back(0);
        }

        // Combine the result
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums{
        0, 1, 0, 3, 12
        // 1,0
    };

    solution.moveZeroes(nums);

    cout << "done";
    return 0;
}

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {

//         int adjusted_index = 0;
//         bool needs_replacement = false;
//         unordered_map<int, int> real_to_adj_indices;
//         set<int> replace;

//         for (int i = 0; i < nums.size(); i++) {
//             replace.insert(i);
//             if (nums[i] == 0 && i != nums.size() - 1) {
//                 needs_replacement = true;
//                 real_to_adj_indices.insert(pair<int, int> (i,
//                     static_cast<int>(nums.size()) - 1 + adjusted_index--));
//             } else {
//                 real_to_adj_indices.insert(
//                     pair<int, int> (i, i  + adjusted_index));
//             }
//         }

//         if (!needs_replacement)
//             return;

//         int moved = nums[0], replaced=nums[real_to_adj_indices.at(0)], next_to_replace = 0;

//         while (!replace.empty()) {
//                     nums[real_to_adj_indices.at(next_to_replace)] = moved;
//                     replace.erase(next_to_replace);
//                     next_to_replace = real_to_adj_indices.at(next_to_replace);
//                     moved = replaced;
//                     replaced = nums[real_to_adj_indices.at(next_to_replace)];
//         }
//     }
// };