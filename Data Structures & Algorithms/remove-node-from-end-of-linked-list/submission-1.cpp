/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head;
        ListNode* second=head;
        while(n>0){
            second=second->next;
            n--;
        }
        ListNode* prev = nullptr;
        while(second){
            second=second->next;
            ListNode* temp = first->next;
            prev = first;
            first = temp;
        }
        if(prev){
            prev->next = first->next;
        }
        else{
            head=head->next;
        }
        return head;
    }
};
