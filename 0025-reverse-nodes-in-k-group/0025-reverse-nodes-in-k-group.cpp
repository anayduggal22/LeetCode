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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> arr;
        ListNode* p = head;

        while (p != NULL) {
            arr.push_back(p->val);
            p = p->next;
        }

        for (int i = 0; i + k <= arr.size(); i = i + k) {

            int low = i;
            int high = i + k - 1;

            while (low <= high) {
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
                low++;
                high--;
            }
        }

        head->val = arr[0];
        head->next = NULL;
        ListNode* ptr = head;

        for (int i = 1; i < arr.size(); i++) {

            ListNode* temp = new ListNode();
            temp->val = arr[i];
            temp->next = NULL;
            ptr->next = temp;
            ptr = temp;
        }

        return head;
    }
};