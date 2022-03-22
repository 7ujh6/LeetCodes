#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>


using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, set<string>> lookup_toggle;
        vector<string> letter_combinations;

        for (int i = 2; i < 10; i++) {
            switch(i) {
                case 2 : lookup_toggle.insert({2, set<string>({"a", "b", "c"})});
                    break;
                case 3 : lookup_toggle.insert({3, set<string>({"d", "e", "f"})});
                    break;
                case 4 : lookup_toggle.insert({4, set<string>({"g", "h", "i"})});
                    break;
                case 5 : lookup_toggle.insert({5, set<string>({"j", "k", "l"})});
                    break;
                case 6 : lookup_toggle.insert({6, set<string>({"m", "n", "o"})});
                    break;
                case 7 : lookup_toggle.insert({7, set<string>({"p", "q", "r", "s"})});
                    break;
                case 8 : lookup_toggle.insert({8, set<string>({"t", "u", "v"})});
                    break;
                case 9 : lookup_toggle.insert({9, set<string>({"w", "x", "y", "z"})});
                    break;  
            }
        }

        backtrack(lookup_toggle, 0, digits, "", letter_combinations);
        return letter_combinations;
        
    }

    void backtrack(const unordered_map<int, set<string>>& lookup_toggle, int index,
     string& digits, string curr_string, vector<string>& letter_combinations) {
        if (index >= digits.length()) {
            letter_combinations.push_back(curr_string);
            return;
        }

        set<string> combos = lookup_toggle.at(digits[index] - '0');
        while(!combos.empty()) {
            backtrack(lookup_toggle, index+1, digits, curr_string + *combos.begin(), letter_combinations);
            combos.erase(combos.begin());
        }
     }
};


int main () {
    Solution solution;
    string digits = 
    // "23";
    "";
    // "2";


    vector<string> answer = solution.letterCombinations(digits);

    for (string s : answer)
        cout << s << " ";
    
    return 0;
}