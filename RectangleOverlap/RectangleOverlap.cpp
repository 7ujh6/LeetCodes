#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<vector<bool>> coords;
        coords.resize(max(rec1[2], rec2[2]), vector<bool>(max(rec1[3], rec2[3]),false));
        
        for (int i=rec1[0]; i<rec1[2]; i++)
            for (int j=rec1[1]; j<rec1[3]; j++) {
                coords[i][j] = true;
            }
        // We don't care about the edges if they overlap
        
        for (int i=rec2[0]; i<=rec2[2]; i++) 
            for (int j=rec2[1]; j<=rec2[3]; j++) 
                if (coords[i][j])
                    return true;
        
        return false;  
    }
};

int main () {
    Solution solution;
    vector<vector<int>> inputs =  {
        {0,0,2,2},
        {1,1,3,3}
    };

    bool answer = solution.isRectangleOverlap(inputs[0], inputs[1]);
    cout << answer << endl;
}

// class Solution {
// public:
//     string longestPalindrome(string s) {
        
//         string longest = "";
//         int longestLength = 0, sLength = s.length();
        
//         for (int i=0; i<sLength; i++) {
//             for (int j=i,k=i; j+1 && k-sLength;) {
//                 cout << "j " << j << " k "  << k << endl;
//                     cout << "s[j] " << s[j] << " s[k] " << s[k] << " eval: " << (s[j] == s[k])  << endl;
//                 if (s[j] == s[k]){
//                     cout << "k-j+1: " << (k-j+1) << " eval: "  << (((k-j+1) > longestLength)) << endl;
//                     if ((k-j+1) > longestLength) {
//                         longestLength = k - j + 1; longest = s.substr(j, k+1);
//                         cout << "substr: " << s.substr(j, k+1) << endl;
//                     }
//                 } else
//                     break;   
//                 j = j-1+1 ? j - 1 : j, k = k + 1 - sLength ? k + 1 : k;
//                 cout << "After changing: " << "j " << j << " k " << k << endl;  
//             }
//         }
        
//         return longest;
//     }
// };