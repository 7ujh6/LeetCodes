#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;

        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {
         7,1,5,3,6,4
        // 7,6,4,3,1
        // 2,4,1
    };

    cout << solution.maxProfit(prices);

    return 0;
}