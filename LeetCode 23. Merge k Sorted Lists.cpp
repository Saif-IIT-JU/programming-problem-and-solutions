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
        ListNode *head = NULL, *node = NULL;

        while(true)
        {
            int j = -1, mn = 1e9;
            for(int i=0; i<lists.size(); i++)
            {
                if(lists[i]!=NULL){
                    if(lists[i]->val<mn){
                        mn = lists[i]->val; j = i;
                    }
                }
            }
            if(j==-1) break;
            if(head==NULL){
                head = lists[j];
                node = head;
            }
            else{
                node->next = lists[j];
                node = node->next;
            }

            lists[j] = lists[j]->next;
        }
        if(head!=NULL) node->next = NULL;

        return head;
    }
};
