#include <iostream>
#include <unordered_map>
#include <set>

///BROKEN POINTERS ARE HARD!!!

using namespace std;
// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// Follow up:
// Could you do get and put in O(1) time complexity?

struct TwoWayListNode {
    int val;
    int key;
    TwoWayListNode *next, *prev;
    TwoWayListNode() : val(-1), next(nullptr) {}
    TwoWayListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    TwoWayListNode(int v, TwoWayListNode *next, TwoWayListNode* prev) : 
        val(v), next(next), prev(prev) {}
};


class LRUCache {
    int capacity, size = 0;
    TwoWayListNode *head = nullptr, *tail = nullptr;
    set<int> lookup;
    unordered_map<int, TwoWayListNode**> store;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!lookup.count(key))
            return -1;
        if (size == 1)
            return (*store.at(key))->val;

        TwoWayListNode** ref = store.at(key);
        // TwoWayNode* value  = *ref;
    
        if ((*ref)->next && (*ref)->prev) {
            cout << (*ref)->next->val << " " << 
                (*ref)->prev->val;
            (*ref)->next->prev = (*ref)->prev;
            (*ref)->prev->next = (*ref)->next;
        } else if ((*ref)->next) {
            //elem is at the head of list
            return (*ref)->val;
            //the head of the list is already the most current
        } else {
            //elem is at the tail of list
            (*ref)->prev->next = nullptr;
        }

        head->prev = *ref;
        (*ref)->next = head;
        head = head->prev;
        store.erase(key);
        store.insert({key, ref});
        return (*ref)->val;
    }
    
    void put(int key, int value) {
        if (!head) {
            head = new TwoWayListNode(key, value);;
            tail = head, size++;
            store.insert({key, &head});
            lookup.insert(key);
            return;
        }

        if(++size > capacity) {
            store.erase(tail->key);
            lookup.erase(key);
            tail = tail->prev;
            tail->next->prev = nullptr;
            tail->next = nullptr;
        }

        TwoWayListNode* node = new TwoWayListNode(key, value);

        if (!store.insert({key, &node}).second) {
            (*store.at(key))->val = value;
            (*store.at(key))->next->prev = (*store.at(key))->prev;
            (*store.at(key))->prev->next = (*store.at(key))->next;
            head->prev = *store.at(key);
            (*store.at(key))->next = head;
            head = head->prev;
        } else {
            head->prev = node;
            node->next = head;
            store.erase(head->key);
            head = head->prev;
            store.insert({head->next->key, &head->next});
            lookup.insert(key);
        }   
    }
};

int main () {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout <<  lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout  << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;    // return 4

    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */