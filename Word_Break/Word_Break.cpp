#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> realDict = toDict(wordDict);
        string tempWord = "";
        bool isSplittable;
        
        for (char elem : s) {
            tempWord += elem;

            if (realDict.count(tempWord)) {
                isSplittable = true;
                tempWord = "";
            }

            else
                isSplittable = false;
        }

        return isSplittable;    
    }

    set<string> toDict (vector<string>& wordDict) {
        set<string> realDict;

        for (string s: wordDict) 
            realDict.insert(s);
    
        return realDict;
    }
};

//to validly split the string all words must be found within the wordDict
//I guess we are to assume case-sensitivity

int main () {
    Solution solution;
    string s = 
    "aaaaaaa";
    // "catsandog";
    // "applepenapple";
    // "leetcode";

    vector<string> wordDict = {
        // "leet",
        // "code"
        // "apple",
        // "pen"
        // "cats",
        // "dogs",
        // "sand",
        // "and",
        // "cat" 
        "aaaa",
        "aaa"

    };

    cout << solution.wordBreak(s, wordDict);
    return 0;
}