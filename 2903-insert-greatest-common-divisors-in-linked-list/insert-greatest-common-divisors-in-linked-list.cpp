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
    int gcd(int a,int b) {
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp = head;

        while(tmp->next) {
            int val = gcd(tmp->val,tmp->next->val);
            ListNode* neww = new ListNode();
            ListNode* sus = tmp->next;
            neww->val = val;
            tmp->next = neww;
            neww->next = sus;
            tmp = sus ;
        }

        return head;
    }
};