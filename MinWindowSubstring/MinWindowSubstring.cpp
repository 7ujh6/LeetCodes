#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

// TODO we need a data structure that deletes a item irregardless of if it is 
// at the front of the queue.
// B does not get updated because A is the front of the stack. B needed to get updated tho.
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, pair<int, int>> lastOccurrences;
        queue<pair<char,int>> window;
        long left=-1, right=s.length()+1;

        // TODO make this work in the case of repeating chars in the substr
        // we're using a map which doesn't account for multiples have to figure out
        // that logic... input of: "aa" "aa" -> "aa"
        
        for (char c: t) lastOccurrences.insert({c, {0, -1}});

        for (int i=0;i<s.length();i++) {
            if (!lastOccurrences.insert({s[i], {0, -1}}).second) 
                lastOccurrences.at(s[i]).first++;   
        }
        
        for (int i=0;i<s.length();i++) {
            if (lastOccurrences.count(s[i])) {
                if (!window.empty() &&  s[i] == window.front().first && !lastOccurrences.at(s[i]).first) 
                    lastOccurrences.at(s[i]).first++, window.pop();
                window.push({s[i], i}), lastOccurrences.at(s[i]).first--, lastOccurrences.at(s[i]).second = i;
                while (lastOccurrences.at(window.front().first).second != window.front().second)
                    lastOccurrences.at(s[i]).first++, window.pop();
            }

            if (window.size() == t.length() && right - left > i - lastOccurrences.at(window.front().first).second) {
                left = window.front().second, right = i;
            }
        } 

        if (!(right-left)) return s;
        if (!(left+1)) return "";
        return s.substr(left, right);
    }    
};

int main () {
    Solution solution;
    string s = "aa", t = "aa";
    cout << solution.minWindow(s, t) << endl;
    return 0;
}