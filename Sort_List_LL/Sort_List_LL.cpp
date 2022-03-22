#include <iostream>
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head, *slow = head, *fast = head;

        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = nullptr;

        return merge(sortList(head), sortList(slow));
    }

    ListNode* merge (ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(numeric_limits<int>::min());
        ListNode* curr = temp;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
            l1 = l1->next;
        }

        if (l2) {
            curr->next = l2;
            l2 = l2->next;
        }

        return temp->next;
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
        // 4,2,1,3
        // -1,5,3,4,0
        
    };

    ListNode* head =  intialize_list(init_list);
    ListNode* answer = solution.sortList(head);

    while (answer) {
        cout << answer->val << (answer->next ? "-" : "");
        answer = answer->next;
    }

    return 0;
}
