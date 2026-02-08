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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        vector<int> store;
        for(int i = 0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp !=NULL){
                store.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(store.begin(),store.end());
        ListNode* tmy = new ListNode(-1);
        ListNode* t = tmy;
        int i = 0;
        while(i < store.size()){
            ListNode* newnode = new ListNode(store[i]);
            t->next = newnode;
            t = t->next;
            i++;
        }
        return tmy->next;
    }
};