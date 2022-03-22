#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//index to prev (pointing) address
//when curr == stored_index --> take the address that is stored at in the map 
//@ index and then assign the curr address to the random field of the stored_address
//all the while next == next address


//Wow.... so the answer is two passes lol...

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clones;

        if (!head)
            return nullptr;

        Node* curr = head;

        while (curr != nullptr) {
            clones.insert({curr, new Node(curr->val)});
            curr = curr->next;
        }
        
        curr = head;

        while (curr != nullptr) {
            if (curr->next)
                clones.at(curr)->next = clones.at(curr->next);

            if (curr->random)
                clones.at(curr)->random = clones.at(curr->random);
        
            curr = curr->next;
        }

        return clones.at(head);
    }
};


int main() {

    Solution solution;

    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node* head_cpy = solution.copyRandomList(head);

    cout << "done";

    return 0;
}