#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * slow=head, * fast=head, * prev = nullptr, * lastTail = nullptr;
        bool headSet=false;
        
        for (;slow;) {
            for (int it = k; fast && it>1; fast=fast->next,it--);
            for (;!fast && slow;lastTail->next=slow, lastTail=lastTail->next,slow=slow->next);
            if (fast && slow && lastTail) lastTail->next = fast;
            if (prev && !headSet) head = prev, headSet=true;
            fast = fast ? fast->next : fast, prev = nullptr;

            for (ListNode * next, * curr=slow; curr != fast;) {
                next = curr->next;
                curr->next = prev;
                prev = curr, curr = next;
            }

            if (slow==head && !fast) return prev;
            lastTail=slow, slow=fast; 
        }
        
        return head;
    }
};

int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2), head->next->next = new ListNode(3), head->next->next->next = new ListNode(4),
    head->next->next->next->next = new ListNode(5);

    int k = 1;

    ListNode * answer = solution.reverseKGroup(head, k);

    for (;answer;)
        cout << answer->val  << " ", answer = answer->next;
    
    cout << endl;  
    return 0;
}