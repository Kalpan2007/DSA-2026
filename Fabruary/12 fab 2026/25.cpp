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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    // Function to check if at least k nodes are present
    bool hasKNodes(ListNode* head, int k) {
        int count = 0;
        while (head && count < k) {
            head = head->next;
            count++;
        }
        return count == k;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        if (!hasKNodes(head, k))
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;

        int count = 0;
        while (curr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        if (nextNode) {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev;
    }
};
