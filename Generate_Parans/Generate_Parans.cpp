#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, "", 0, 0, n);
        return output;
    }

    void backtrack(vector<string>& output, string curr_string, int open,
    int close, int max) {

        if (curr_string.length() == max * 2) {
            output.push_back(curr_string);
            return;
        }

        if (open < max) backtrack(output, curr_string + "(" , open + 1, close, max);
        if (close < open) backtrack(output, curr_string + ")", open, close + 1, max);
    }
};



int main() {

    Solution solution;
    int n = 3;

    vector<string> answer = solution.generateParenthesis(n);

    for (string s : answer)
        cout << s << endl;

    return 0;
}