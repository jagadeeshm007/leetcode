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
    ListNode* middleNode(ListNode* head) {
        ListNode* t = head;
        ListNode* r = head;
        while(r->next!=NULL && r->next->next!=NULL){
            t=t->next;
            r=r->next->next;
        }
        if(r->next !=NULL) return t->next;
        return t;
    }
};