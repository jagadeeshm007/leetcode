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
       ListNode* fast = head;
       ListNode* slow = head;
       ListNode* ans = slow;
       int fst=n+1,len =0;
       while(fast){
        if(fst>0){
            fst--;
        }
        else{
            slow = slow->next;
        }
        fast = fast->next;
        len++;
       }
       if(len == n){
        return head->next;
       }
       if(slow->next->next == NULL){
         slow->next = NULL;
       }
       else{
        slow->next = slow->next->next;
       }
       //if(slow!=NULL) cout<<slow->val<<endl;
       return ans;
    }
};