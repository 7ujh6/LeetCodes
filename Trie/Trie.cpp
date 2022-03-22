#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Trie {
    int val;
    vector<Trie*> children;
    unordered_set<string> store;

public:
    /** Initialize your data structure here. */
    Trie() {children.resize(26, nullptr);}
    Trie(int x) : val(x) {children.resize(26, nullptr);}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!store.insert(word).second)
            return; //word is already in store --> no need to populate tree

        Trie* child = children[word[0] - 'a'];

        if (!child) {
            child = new Trie(word[0]);
            children[word[0] - 'a'] = child;
            for (int i=1; i<word.length();i++) {
                Trie* granchild = new Trie(word[i]);
                child->children[word[i] - 'a'] = granchild;
                child = granchild;
            }
        } else {
            int off = 1;
            int offset = 1;
            for(;off<word.length() && child->children[word[off]-'a']; off++)
                child = child->children[word[off] - 'a'];
            for (;off < word.length(); off++) { //for the rest of the word
                Trie* granchild = new Trie(word[off]);
                child->children[word[off] - 'a'] = granchild;
                child = granchild;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return store.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        if (store.count(prefix))
            return true;

        Trie* current = prefix.length() ? 
            children[prefix[0]-'a'] : nullptr;

        for (int i=1; i<prefix.length(); i++) {
            if (!current)
                return false;
            current = current->children[prefix[i]-'a'];
            if (!current)
                return false;
        }

        return current;
    }
};

int main () {
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple");   // return True
    cout << trie.search("app");     // return False
    cout << trie.startsWith("app"); // return True
    trie.insert("app");
    cout << trie.search("app");     // return True
    return 0;

    // cout << trie.startsWith("a");
    
    // trie.insert("ab");
    // cout << trie.search("abc");
    // cout << trie.search("ab");
    // cout << trie.startsWith("abc");
    // cout << trie.startsWith("ab");
    // trie.insert("ab");
    // cout << trie.search("abc");
    // cout << trie.startsWith("abc");
    // trie.insert("abc");
    // cout << trie.search("abc");
    // cout << trie.startsWith("abc");

    // trie.insert("p");
    // trie.insert("pr");
    // trie.insert("pre");
    // trie.insert("pref");
    // trie.insert("prefi");
    // trie.insert("prefix");

    return 0;

}