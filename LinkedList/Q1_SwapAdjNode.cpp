/*

leetcode 24 - swap nodes in pairs  

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* dummy = temp;
        while (dummy->next != NULL && dummy->next->next != NULL) {
            ListNode* swap1 = dummy->next;
            ListNode* swap2 = dummy->next->next;
            swap1->next = swap2->next;
            swap2->next = swap1;
            dummy->next = swap2;
            dummy = swap1;
        }
        return temp->next;
    }
};

*/