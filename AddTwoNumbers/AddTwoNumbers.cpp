#include <string>
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
    ListNode* rl1, * rl2, * head = new ListNode();
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse(nullptr, l1, &(rl1));
        // reverse(nullptr, l2, &(rl2));

        return traverseAndSum(l1, l2, head, head, &(head), 0);
    }

    // void reverse(ListNode* prev, ListNode* root, ListNode** head) {
    //     ListNode* next = root->next;
    //     root->next = prev;
    //     if (next)
    //         reverse(root, next, head);
    //     else
    //         *head = root;
    // }
    
    ListNode* traverseAndSum (ListNode* l1, ListNode* l2, ListNode* sumCurr, ListNode* sumPrev, ListNode** sumHead, int carry) {
        string sum;

        if (!l1 && !l2) {
            sumPrev->next = carry ? new ListNode(carry) : nullptr;
            return head = *sumHead;
        }
        else if (!l1)
            sum = to_string(0 + l2->val + carry);
        else if (!l2)
            sum = to_string(l1->val + 0 + carry);
        else
            sum = to_string(l1->val + l2->val + carry);
        
        sumCurr->next = new ListNode(0);
        carry = sum.length() > 1 ? sum[0] - '0' : 0;  
        sumCurr->val = sum.back() - '0';

        int converted = 0;

        max(numeric_limits<int>::min(), min(converted, numeric_limits<int>::max()));
        
        return traverseAndSum(l1 ? l1->next: l1, l2 ? l2->next : l2, sumCurr->next, sumCurr, sumHead, carry);    
    }
};

int main() {
    Solution solution;

    // l1 = [2,4,3], l2 = [5,6,4]

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode * head = solution.addTwoNumbers(l1, l2), * curr = head;
    cout << endl;

    while (curr) {
        cout << curr->val << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << endl;
    
    return 0;
}