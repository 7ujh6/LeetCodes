#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;



class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};



int main() {
    Solution solution;
    string s =
        // "3[a]2[bc]"; // "aaabcbc"
        // "3[a2[c]]"; // "accaccacc"
        // "2[abc]3[cd]ef"; // "abcabccdcdcdef"
        "abc3[cd]xyz"; // "abccdcdcdxyz"
        cout << endl << solution.decodeString(s);
    return 0;
}

/*
/// Doesn't work but useful functions:

class Solution {
public:

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}
    string decodeString(string s) {
        vector<string> split_string;
        ReplaceStringInPlace(s, "[", " ");
        ReplaceStringInPlace(s, "]", " ");

        size_t pos = 0;
        string token, delimiter=" ", ans;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            split_string.push_back(token);
            s.erase(0, pos + delimiter.length());
        }

        for (int i=0; i<split_string.size(); i+=2) {
            int iterations = stoi(split_string[i]);
            for(int j=0; j<iterations;j++) 
                ans+=split_string[i+1];
        }

        return ans;
    }
};

*/