#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        double phi = (1 + sqrt(5)) / 2; 
        return round(pow(phi, ++n) / sqrt(5));
        
    }
};

int main () {

    Solution solution;

    cout << solution.climbStairs(
        //3
        4
    );

    return 0;
}