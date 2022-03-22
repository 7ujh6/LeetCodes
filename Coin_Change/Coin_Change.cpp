#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        sort(coins.begin(), coins.end());
        int size_c = coins.size(), size_a = dp.size();
        dp[0] = 0;
        
        for (int i=1;i<size_a;i++) {
            for (int j=0;j<size_c;j++) {
                if (i-coins[j] > -1) {// if every coin fails then dp[i] == -1 else change it's val
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                } else break;
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
        
    }
};

int main() {
    Solution solution;
    int amount = 
    // 11;
    // 3;
    // 0;
    // 1;
    2;
    vector<int> coins = {
        // 1,2,5 // out: 3
        // 2 // out: -1
        // 1 // out: 0
        // 1 // out: 1
        1 // out: 2
    };
    cout << solution.coinChange(coins, amount);
    return 0;
}