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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next==NULL) return head;
        else if(head->next->next==NULL){
            head->next->next=head;
            ListNode *tx=head->next;
            head->next=NULL;
            return tx;
        }
        else{
            ListNode *temp=head;
            ListNode *s=temp->next->next;
            ListNode *t=temp->next;
            temp->next->next = temp;
            temp->next=NULL;
            temp=t;
            while(s->next){
                t=s;
                s=s->next;
                t->next=temp;
                temp=t;
            }
            s->next=temp;
            return s;
        }
    }
};