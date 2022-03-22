#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Two approaches: 
//1-> store encountered nums in a priority queue of pairs: {index, val}
//while iterating i to j if i is queue.top->index is ever less than i, 
//pop that value from the queue... pop until index >= i


//2-> iterate through the array i to j if A[j] > A[j-1], A[j-2]...A[i], A[j-1]..A[i]
//=A[j], stop when A[j-x] is > A[j] The max in the window is always contained at the 
//last aka ith index -> A[i] = max of that window

//Pros & Cons: 1 -> more space intensive but its time constraints may be more efficient
// than approach 2

// 2 -> less space intensive, comparable time constraint to approach 1

//Approach 2 -> Time Limit Exceeded.


struct PairComparator {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, PairComparator> max;
        vector<int> ans;
        int first = 0, last = k-1;

        for (int i=0; i<k;i++)
            max.push({i, nums[i]});
        
        for (;last<nums.size();first++,last++) {
            while (!max.empty() && max.top().first < first)
                max.pop();
            max.push({last, nums[last]});

            ans.push_back(max.top().second);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int k =
        3;
        // 1;
        // 1;
        // 2;
        // 2;
    vector<int> nums = {
        1,3,-1,-3,5,3,6,7 // out: 3,3,5,5,6,7
        // 1    // out: 1
        // 1,-1 // out: 1
        // 9,11 // out: 11
        // 4,-2 // out: 4
    };

    vector<int> answer = solution.maxSlidingWindow(nums, k);

    for (int elem : answer) 
        cout << elem;
    return 0;
}

///Approach 2 -> Time Limit Exceeded
/* 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int first=0, last=k-1;
        vector<int> ans;

        for (int i=last; i>0; i--)
            nums[i-1] = nums[i]>nums[i-1] ? nums[i] : nums[i-1];
        
        for (;last<nums.size(); first++, last++) {
            for(int i=last; i&&nums[i-1]<nums[i]; i--)
                nums[i-1] = nums[i];

            ans.push_back(nums[first]);
        }

        return ans;
    }
};
*/