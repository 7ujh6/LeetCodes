#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (ceil(sqrt(n))==floor(sqrt(n)))
            return 1;
        
        while (n%4==0)
            n/=4;
        
        if (n%8==7)
            return 4;

        for (int i=1;i*i<=n;++i) {
            int base = sqrt(n-i*i);
            if(base*base==(n-i*i))
                return 2;
        }

        return 3;

    }
};

int main() {
    Solution solution;
    int n = 
    // 12;
    13;

    cout << solution.numSquares(n);
    return 0;
}

//What x numbers add up to equal n? (The question):

// 12: 12, 1 11; 2 10; 3 9; 4 8; 5 7; 6 6; 7 5; 8 4; 9 3; 10 2; 11 1
// 12: 10 1 1; 9 1 2; 8 2 2...
// of those groups how many have all perfect square members?
// if none, x++ -> repeat the process
// We can simply this proccess by only subtracting perfect squares
// ->do not generate every sequence of nos just the perfect sums
// however this is still a brute force approach. Can we be more efficient?


// 13: 13, 1 12, 2 11, 3 10, 4 9, 5 8, 6 7, 7 6, 8 5, 9 4, 10 3, 11 2, 12 1

///fibonaci sequence for squares????
/// 1 4 -> 5 -> 9 -> 14 -> 23
// 


/// DP Solution (DP Tabulation)
/*
    // The idea is to cache the number of steps it takes to get
    // to the solution not the previous (intimediary) values themselves;
class Solution {
    public:
        int numSquares(int n) {
            int dp[n+1];
            dp[0] = 0;

            for (int i=1;i<=n;++i) {
                dp[i] = i;
                for(int j=1;j*j<=i;++j) {
                    int sq = j*j;
                    dp[i] = min(dp[i],1+dp[i-sq]);
                }
                return dp[n];
            }
        }
}

*/