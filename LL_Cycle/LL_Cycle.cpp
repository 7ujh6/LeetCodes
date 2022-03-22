#include <iostream>

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
    bool hasCycle(ListNode *head) {

        if (!head)
            return false;

        ListNode* current = head;

        while (current != nullptr) {
            if (current->val == numeric_limits<int>::max())
                return true;

            ListNode* temp = current->next;
            current->next = new ListNode(numeric_limits<int>::max());
            current = temp;

        }

        return false;
    }
};

int main() {
    Solution solution;

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next = head->next;

    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = head;

    // ListNode* head = new ListNode(1);

    // ListNode* head = nullptr;


    cout << solution.hasCycle(head);
    return 0;
}