#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pair = pair<int, int>;

struct Pair_Compare {
    bool operator() (const Pair& a, const Pair& b) const
	{
		return a.second < b.second;
	}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        sort(nums.begin(), nums.end()); 
        vector<int> ans, occurrences(nums.size()+1, 100001);
        vector<vector<int>> multiples(2);
        int current = nums[0], count=1;

        /// Bucket Approach
        

        for (int i=1;i<nums.size()+1;i++) {
            if(i==nums.size() || nums[i] != current) {
                if (occurrences[count] > -1) {
                    if (!(occurrences[count]-100001))
                        occurrences[count]=current;
                    else {
                        multiples[occurrences[count]].push_back(occurrences[count]);
                        multiples[occurrences[count]].push_back(current);
                        occurrences[count]=-(multiples.size()-1);
                    }
                } else 
                    multiples[-occurrences[count]].push_back(current);
                current=i-nums.size()==0 ? current : nums[i], count=1;
            } else
                count++;
        } 



        for(int i=occurrences.size()-1;k>0;k--,i--) {
            if(!(occurrences[i]-100001)) {
                k++;
                continue;
            }
            if(occurrences[i] > -1) 
                ans.push_back(occurrences[i]);
            else {
                for(int j=0;k&&j<multiples[-occurrences[i]].size();j++,k--) {
                    ans.push_back(multiples[-occurrences[i]][j]);
                }
            }
        }

        return ans;
    }

    // 1,1,1,2,2,3 ... 3,2,1 ... 1,2,3
    //              -- sort -- 
    // if we can apply a sort on the range of indices that we want to sort
    // and the apply that same transformation on the other set
    // this solution requires you to know the amount of unique values in the array
};

int main() {
    Solution solution;
    int k =
    2;
    // 1;
    // 1;
    vector<int> nums = {
        1,1,1,2,2,3
        // 1
        // 3,0,1,0
    };
    
    vector<int> ans = solution.topKFrequent(nums, k);
    cout << '[';
    for (int elem: ans)
        cout << elem << ',';
    cout << ']';
    return 0;
}

/*
/// Works
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        vector<int> ans;
        priority_queue<Pair, vector<Pair>, Pair_Compare> occurrences;
        sort(nums.begin(), nums.end());
        int current=nums[0], count=1, end=nums.size();
        
        for (int i=1;i<end;i++) {
            if (nums[i] != current) {
                occurrences.push({current, count});
                current=nums[i], count=1;
            } else
                count++;
        }

        occurrences.push({current, count});

        while(k && !occurrences.empty()) 
            ans.push_back(occurrences.top().first), occurrences.pop(), k--;
        
    
        return ans;
    }

    // 1,1,1,2,2,3 ... 3,2,1 ... 1,2,3
    //              -- sort -- 
    // if we can apply a sort on the range of indices that we want to sort
    // and the apply that same transformation on the other set
    // this solution requires you to know the amount of unique values in the array
};


*/

/*
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]

1 <= nums.legth <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

*/


/*
if (nums[i] != current) {
                nums[end+i-1] = current;
                nums[end+i] = occurrences;
                current = nums[i];
                occurrences = 1;
            } else 
                occurences++, k--;
*/