#include <bits/stdc++.h>

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode result(0);
    ListNode *currentList = &result;
    int carry = 0;
    while (l1 || l2) {
      carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      currentList->next = new ListNode(carry % 10);
      carry /= 10;

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;

      currentList = currentList->next;
    }

    if (carry) {
      currentList->next = new ListNode(1);
    }

    return result.next;
  }
};