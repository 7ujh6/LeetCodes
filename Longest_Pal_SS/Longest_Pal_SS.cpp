#include <iostream>
#include <string>

using namespace std;

/*Solution algo: 
    So, at a minimum palindrome must have it's matching char be next to it or 2 away--
    bab or bb (base case);
    
    You can iterate through the array and the stop when at the index
    'bab'(012) or 'bb'(01) is satisfied. Then from this base string you can build up        the longest palindromic substring by validating other cases you know that the          next closets care has to match an index that is 1 further than the previous            match-- 'ababa'(01234) or 'abba' (0123). You keep back tricking the string and
     then you stop when either the beginning of this list is reached or the check          fails-- at which point, you record the index at which the process is stops and if
     the (current_index - stopping_index) * 2 is larger than the max substring, then      max_substring becomes that string (will have to compose the string from 1 half      but the other half is just a mirror of the first so it is trivial to do) else        increment the index.
     
     return max_substring when the end of the string is reached.
     
     Don't check string[i + 2] or string[i + 1] if at index of size - 2 or size - 1
     respectively.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string answer=string(1, s[0]), temp="";
        int offset;

        for (int i = 0; i < s.size(); i++) {

            int curr = i;
            if ( i+1 < s.size() && s[i+1] == s[i]) {
                // answer="";
                temp.push_back(s[i]);
                temp.insert(0,1,s[i]);
                offset = 1;
                curr--;
            } else if (i+2 < s.size() && s[i+2] == s[i]) {
                // answer="";
                temp.push_back(s[i+1]);
                temp.push_back(s[i]);
                temp.insert(0, 1, s[i]);
                offset = 2;
                curr--;
            } else
                continue;

            while(curr >= 0) {
            
                if(s[i+offset] == s[curr]) {
                    temp.push_back(s[curr]);
                    temp.insert(0, 1, s[curr]);
                    offset++;
                    curr--;
                } else 
                    break;
            }

            answer = temp.size() > answer.size() ? temp : answer;
            temp="";
        }
        return answer;
    }
};

int main () {
    Solution solution;
    string s = 
        // "babad";
        // "cbbd";
        // "a";
        // "ac";
        "ccc";

    cout << endl << solution.longestPalindrome(s);
    
    return 0;
}