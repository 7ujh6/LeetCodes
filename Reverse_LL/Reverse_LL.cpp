#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        vector<int> v_list;
        ListNode* current = head;

        while (current != nullptr) {
            v_list.push_back(current->val);
            current = current->next;
        }

        ListNode* rhead = new ListNode(v_list[v_list.size() - 1]),
            * rcurrent = rhead;

        for (int i = v_list.size() - 2; i >=0; i--) {
            rcurrent->next = new ListNode(v_list[i]);
            rcurrent = rcurrent->next;
        }

        return rhead;
        
    }
};

ListNode* intialize_list (vector<int> init_list) {

    if (init_list.size() == 0)
        return nullptr;

    ListNode* head = new ListNode(init_list[0]),
        * current = head;
            
    for (int i=1; i < init_list.size(); i++) {
        current->next = new ListNode(init_list[i]);
        current =  current->next; 
    }

    return head;
}

int main() {
    Solution solution;
    vector<int> init_list = {
        // 1, 2, 3, 4, 5
        // 1, 2, 3, 4
        0,1,4,-2
    };

    ListNode* head =  intialize_list(init_list);
    ListNode* rhead = solution.reverseList(head);

    while (rhead != nullptr) {
        cout << rhead->val;
        rhead = rhead->next;
    }

    return 0;
}