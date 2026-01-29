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
        int length = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        int traverseTill = length - n - 1;
        int i = 0;
        curr = head;

        if (traverseTill == -1) {
            head = head->next;
            delete curr;
            return head;
        }

        while (i < traverseTill) {
            curr = curr->next;
            i++;
        }

        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};