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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *currNode = head;
        if (!currNode) {
            return nullptr;
        }
        
        while(currNode->next) {
            if (currNode->val == currNode->next->val) {
                currNode->next = currNode->next->next;
                continue;
            }
            currNode = currNode->next;
        }
        
        return head;
    }
};