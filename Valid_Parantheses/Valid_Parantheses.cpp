#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        if (s.size() == 0)
            return false;

        stack<char> prevOpening;
        unordered_map<char, char> matching_brace = {{'>', '<'}, {'}', '{'}, {')', '('}, {']', '['}};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '(') 
                prevOpening.push(s[i]);
            else {
                if (!prevOpening.empty() && prevOpening.top() == matching_brace.at(s[i]))
                    prevOpening.pop();
                else
                    return false;
            }
        }

        if (!prevOpening.empty())
            return false;

        return true;
    }
};

int main()
{
    Solution solution;
    string s = // "]";
    // "[(])";
    // "[()]{}{[()()]()}";
    // "{{}}()[()]";
    // "{][}";
    // "()(";
    // "(]";
    // "()[]{}";
     "()";

    cout << solution.isValid(s);

    return 0;
}