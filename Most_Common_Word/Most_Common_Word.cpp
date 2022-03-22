#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedDict;
        unordered_map<string, int> occurrences;
        for (string s: banned) bannedDict.insert(s);
        
        string mostFrequent = "";
        int topFrequency = 0;
        
        for (int i=0; i<paragraph.length(); paragraph[i]=tolower(paragraph[i]),i++);
        
        
        for (int i=0, j=0; i<paragraph.length(); i=j) {
            for(;i<paragraph.length() && (paragraph[i]=='!' || paragraph[i]=='?' || paragraph[i]=='\'' || paragraph[i]==',' || paragraph[i]==';' || paragraph[i]=='.' || paragraph[i]==' '); i++);
            
            for(j=i;j<paragraph.length() && paragraph[j]!='!' && paragraph[j]!='?' && paragraph[j]!='\'' && paragraph[j]!=',' && paragraph[j]!=';' && paragraph[j]!='.' && paragraph[j]!=' '; j++);
            string word = paragraph.substr(i,j-i);
            if (!occurrences.insert({word, 1}).second) occurrences.at(word)++;
            if (!bannedDict.count(word) && occurrences.at(word) > topFrequency)
                mostFrequent = word, topFrequency = occurrences.at(word);
        }
        
        return mostFrequent;
    }
};

int main() {
    Solution solution;
    string paragraph = 
    "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    cout << solution.mostCommonWord(paragraph, banned) << endl;
    return 0;
}