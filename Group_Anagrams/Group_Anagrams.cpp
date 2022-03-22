#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//["cab","tin","pew","duh","may","ill","buy","bar","max","doc"]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<long long, int> hash_to_index;

        for (int i=0; i < strs.size(); i++) {
            long long reduce = 1;
            for (char c : strs[i]) {
                reduce *= hash<char>{}(c);
            }

            if (hash_to_index.insert(pair<long long,int>(reduce, groups.size())).second) {
                //If the string is not in the map create a new group
                groups.push_back(vector<string>({strs[i]}));
            } else {
                //Else just append the string to the exisiting group
                groups[hash_to_index.at(reduce)].push_back(strs[i]);
            }

        }

        return groups;
    }
};

int main() {

    Solution solution;
    vector<string> strs = {
        // "eat","tea","tan","ate","nat","bat"
        // "a"
        // ""
        // "cab","tin","pew","duh","may","ill","buy","bar","max","doc"
        // "bdddddddddd", "bbbbbbbbbbc"
        // "hos","jew","nub","cod","old","way","fur","fla","cot","baa","leo","uzi","tho","pry","tun","hex","fog","tad","eat","sow","cop","eke","jam","arc","guy","tow","aid","ann","bus","ten","ate","ewe","roy","leg","gas","bug","jay","sup","phd"
    };

    cout << solution.groupAnagrams(strs)[0][0];

    return 0;

}
/* Very Close 2nd Attempt (110/112) test cases (Hashing is Hard) :(

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<long long, int> hash_to_index;

        for (int i=0; i < strs.size(); i++) {
            long long reduce = 1;
            for (char c : strs[i]) {
                reduce *= hash<char>{}(c);
            }

            if (hash_to_index.insert(pair<long long,int>(reduce, groups.size())).second) {
                //If the string is not in the map create a new group
                groups.push_back(vector<string>({strs[i]}));
            } else {
                //Else just append the string to the exisiting group
                groups[hash_to_index.at(reduce)].push_back(strs[i]);
            }

        }

        return groups;
    }
};

*/

/*  First attempted solution


struct String_Wrapper {
    string value;

    String_Wrapper(string& value) {
        this->value = value;
    }

    bool char_compare(const string& a, const string& b) {
        for (int i=0; i < a.size(); i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    bool operator==(const string& b) {
        return this->value.length() == b.length() &&
            char_compare(this->value, b);
    }

};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        vector<set<String_Wrapper>> order_insensitive;

        order_insensitive.push_back(set<String_Wrapper>());
        groups.push_back(vector<string>());

        order_insensitive[0].insert(String_Wrapper(strs[0]));
        groups.back().push_back(strs[0]);

        for (int i=1; i < strs.size(); i++) {
            bool combo_found;
            for (int j=0; j < order_insensitive.size(); j++) {               
                if (order_insensitive[j].count(String_Wrapper(strs[i]))) {
                    groups[j].push_back(strs[i]);
                    combo_found = true;
                    break;
                } 
            }

            if (!combo_found) {
                    order_insensitive.push_back(set<String_Wrapper>());
                    groups.push_back(vector<string>());

                    order_insensitive.back().insert(String_Wrapper(strs[i]));
                    groups.back().push_back(strs[i]);
                }
        }
        return groups;
    }
};



*/

