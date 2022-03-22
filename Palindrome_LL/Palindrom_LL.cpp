#include <iostream>
#include <stack>
#include <queue>

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
    bool isPalindrome(ListNode* head) {
        queue<int> in_order;
        stack<int> reverse;

        ListNode* current = head;

        while (current != nullptr) {
            in_order.push(current->val);
            reverse.push(current->val);
            current = current->next;
        }

        while (!in_order.empty()) {
            if (in_order.front() != reverse.top()) 
                return false;
            
            in_order.pop();
            reverse.pop();
        }

        return true;
      
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

int main () {
    Solution solution;
    vector<int> init_list = {
        1,2
        // 1,2,2,1
    };

    ListNode* head =  intialize_list(init_list);
    
    cout << solution.isPalindrome(head) ? "true" : false;
    return 0;
}