#include <iostream>
#include <vector>
#include <stack> 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> nodes;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* reference = curr;
            nodes.push(reference);
            curr = curr->next;
        }

        if (nodes.size() == 1) 
            return nullptr;
        
        if(nodes.size() == 2) {
            if (n == 1)
                return new ListNode(head->val);
            else 
                return new ListNode(head->next->val);
        }
        
        if (n == 1) {
            nodes.pop();
            ListNode* previous = nodes.top();
            previous->next = nullptr;
        } else if (n == nodes.size()) { 
            for (int i=1; i < n-1; i++)
                nodes.pop();

            head = nodes.top();
        } else {

            for (int i=1; i < n - 1; i++)
                nodes.pop();
            
            ListNode* next = nodes.top();
            nodes.pop();
            ListNode* remove = nodes.top();
            nodes.pop();
            ListNode* previous = nodes.top();
            nodes.pop();
            
            previous->next = next;
            remove->next = nullptr;
        }
        
        return head;
        
    }
};

ListNode* initialize_list (vector<int> init_list) {

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
    int n = 
    // 2;
    // 1;
    1;
    // 3;

    vector<int> init_list = {
        // 1,2,3,4,5
        // 1
        // 1,2
        1,2,3
    };

    ListNode* head = initialize_list(init_list);

    head = solution.removeNthFromEnd(head, n);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}