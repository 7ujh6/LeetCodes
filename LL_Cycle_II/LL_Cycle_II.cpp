#include <iostream>
#include <set>

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
    ListNode *detectCycle(ListNode *head) {

        if (!head)
            return nullptr;

        ListNode* current = head;
        set<ListNode*> traversed_nodes;

        while (current != nullptr) {
            if (!traversed_nodes.insert(current).second) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }
};

int main() {
    Solution solution;

    // ListNode* head = new ListNode(3);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(-4);
    // head->next->next->next = head->next;

    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = head;

    // ListNode* head = new ListNode(1);

    ListNode* head = nullptr;

    ListNode* answer = solution.detectCycle(head);
    if (answer)
        cout << answer->val;
    else 
        cout << -1;

    return 0;
}