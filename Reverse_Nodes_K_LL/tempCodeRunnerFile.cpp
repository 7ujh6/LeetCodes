class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * slow=head, * fast=head, * prev = nullptr, * lastTail = nullptr;
        bool headSet;
        
        for (;slow;) {
            for (int it = k; fast && it>1; fast=fast->next,it--);
            for (;!fast && slow;lastTail->next=slow, slow=slow->next);
            if (fast && slow && lastTail) lastTail->next = fast;
            if (fast && slow && prev && !headSet) head = prev, headSet=true;
            fast = fast ? fast->next : fast, prev = nullptr;

            for (ListNode * next, * curr=slow; curr != fast;) {
                next = curr->next;
                curr->next = prev;
                prev = curr, curr = next;
            }

            lastTail=slow, slow=fast; 
        }
        
        return head;
    }
};