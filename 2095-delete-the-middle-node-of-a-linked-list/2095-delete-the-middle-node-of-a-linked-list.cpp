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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        int i = 0;
        while(q != NULL && q->next != NULL){
            p = p->next;
            q = q->next->next;
            i++;
        }
        if(!i){
            return NULL;
        }
        q = head;
        while(q->next != p){
            q = q->next;
        }
        q->next = p->next;
        return head;
    }
};