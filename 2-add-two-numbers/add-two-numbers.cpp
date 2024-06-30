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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0,rem=0;
        ListNode* res = new ListNode;
        ListNode* result = res;
        while(l1!=NULL && l2!=NULL){
            int tmp = l1->val+l2->val+carry;
            rem = tmp%10;
            carry = tmp/10;
            res->val=rem;
            l1 = l1->next;
            l2 = l2->next;
            if(!l1 || !l2){
                break;
            }
            ListNode* add = new ListNode;
            res->next = add;
            res = res->next;
        }
        while(l1!=NULL){
            int tmp=l1->val+carry;
            rem = tmp%10;
            carry = tmp/10;
            ListNode* add = new ListNode;
            add->val = rem;
            res->next = add;
            res = res->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int tmp=l2->val+carry;
            rem = tmp%10;
            carry = tmp/10;
            ListNode* add = new ListNode;
            add->val = rem;
            res->next = add;
            res = res->next;
            l2 = l2->next;
        }
        if(carry!=0){
            ListNode* add = new ListNode;
            add->val = carry;
            res->next=add;
        }
        return result;
    }
};