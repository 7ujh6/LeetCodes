#include <string>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int total = 0, left = 0, right = 0, length = s.length();
        vector<vector<bool>> pairs;
        pairs.resize(length, vector<bool>(length, false));


        for (int i = 0; i < length; i++, left = right = i) {
            while (left || (right - length)) {
                if (s[left] == s[right] && !pairs[left][right]) 
                    total++;//, pairs[left][right] = true;    
                
                left = !(left) ? left : left - 1,
                right = !(right - length) ? right : right + 1;
            }
            
        }
        return total;
    }
};


int main () {
    Solution solution;
    string input =
    // "abc"; // 3
    // "aaa"; // 6
    // "aac"; // 4
    // "aba"; // 4
    "baab"; // 6 

    int result = solution.countSubstrings(input);
    cout << result << endl;

    return 0;
}

// b a a b
// 0 1 2 3

// a b a a b a
// 0 1 2 3 4 5

/// Description

/// Attempt 2 (Doesn't work. Can enumerate all palindromic substrings that consist
// consist of the same character but not substrings of different characters)
/*
int choose(int n, int k) {
    if (k == 0) return 1;
    return (n * choose(n - 1, k - 1)) / k;
}

void span(int amount, int& total) {
    total += amount == 1 ? 1 : amount + 1;
    for (int i = 1; i < amount; i++ ) 
        total += choose(amount - i, i);
}

class Solution {
public:
    int countSubstrings(string s) {
        int total = 0, length = s.length(), count = 1, different = 2; 

        if (length == 1)
            return length;      

        for (int i = 1; i < length - 1; i++) {
            if (s[i] != s[i-1] && s[i+1] != s[i]) {
                span(count, total), count = 0, different++,
                    total+= s[i-count] == s[i+1] ? 1 : 0;
                
            } else
                count++;
        }

        if (different == length)
            return different;
        
        if (s[length - 1] != s[length - 2]) 
            span (count, total);
        else 
            span(count + 1, total);

        return total;
    }
};
*/

/*

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.


*/

/// First Attempt

// void recurse(string& s, int position, int& length, int count, vector<int>& chars, int& total) {
    //     if (chars[s[position] - 'a'] < count) {
    //         chars[s[position] - 'a'] = count, total++;
    //     }

    //     if (length > position) {
    //         if (s[position] == s[position + 1])
    //             recurse(s, position + 1, length, count + 1, chars, total);

    //         else if (position+1 != length)
    //             recurse(s, position + 1, length, 1, chars, total);
    //     }
    // }