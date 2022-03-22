trie.insert("apple");
    cout << trie.search("apple");   // return True
    cout << trie.search("app");     // return False
    cout << trie.startsWith("app"); // return True
    trie.insert("app");
    cout << trie.search("app");     // return True
    return 0;