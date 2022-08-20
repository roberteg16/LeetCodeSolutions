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
  ListNode *consumeUntilDiffValOrNull(ListNode *node, int val) {
    while (node && node->val == val) {
      node = node->next;
    }
    return node;
  }

public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *currNode = head;
    ListNode *prevNode = nullptr;
    bool areHeadAndCurrentSame = true;

    while (currNode) {
      if (!currNode->next) {
        return head;
      }

      if (currNode->val == currNode->next->val) {
        ListNode *nextNode = consumeUntilDiffValOrNull(currNode, currNode->val);
        if (areHeadAndCurrentSame) {
          head = currNode = nextNode;
        } else {
          prevNode->next = nextNode;
          currNode = nextNode;
        }
      } else {
        prevNode = currNode;
        currNode = currNode->next;
        areHeadAndCurrentSame = false;
      }
    }

    return head;
  }
};