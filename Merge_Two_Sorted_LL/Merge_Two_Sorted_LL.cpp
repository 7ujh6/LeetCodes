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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode preHead(0), *p = &preHead;
        for (;list1 || list2;) {
            if (list1 && list2) {
                if (list1->val == list2->val)
                    p->next = new ListNode(list1->val), p->next->next = new ListNode(list2->val), p=p->next, list1=list1->next, list2=list2->next;
                else if (list1->val < list2->val)
                    p->next = new ListNode(list1->val), list1=list1->next;
                else 
                    p->next = new ListNode(list2->val), list2=list2->next;
            } else {
                if (list1)
                    p->next = new ListNode(list1->val), list1=list1->next;
                else
                    p->next = new ListNode(list2->val), list2=list2->next;
            }

            p=p->next;      
        } 
        return preHead.next;     
    }
};

int main() {
    Solution solution;
    ListNode *list1 = new ListNode(1), *list2 = new ListNode(1); 
    list1->next = new ListNode(2), list1->next->next = new ListNode(4), list1->next->next = new ListNode(6),
    list1->next->next->next = new ListNode(8), list1->next->next->next->next = new ListNode(9);

    list2->next = new ListNode(3), list2->next->next = new ListNode(17);

    ListNode* answer = solution.mergeTwoLists(list1, list2);

    for (;answer;) {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
    
}