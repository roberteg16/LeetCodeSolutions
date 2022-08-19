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
    struct LenghtAndTail {
      ListNode *Tail = nullptr;
      int Lenght = 0;
    };
    
    LenghtAndTail getLenghtAndTail(ListNode *list) {
        assert(list);
        
        int lenght = 1;
        while (list->next) {
            lenght++;
            list = list->next;
        }
        return LenghtAndTail{list, lenght};
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        
        LenghtAndTail latA = getLenghtAndTail(headA);
        LenghtAndTail latB = getLenghtAndTail(headB);
        
        // If tails are different they cannot intersect
        if (latA.Tail->val != latB.Tail->val) {
            return nullptr;
        }
        
        // Equalize both lists to they are same size, they can start
        // intersecting only once they are equal
        int diff = latA.Lenght - latB.Lenght;
        if (diff > 0) {
           while(diff > 0) {
               headA = headA->next;
               diff--;
           }
        } else while(diff < 0) {
          headB = headB->next;
          diff++;
        }
        
        // Now they are both equal size, so only checking that headA != nullptr
        // also guarantees that headB is also != nullptr.
    
        ListNode *result = nullptr;
        while(headA) {
          // Advance while different values
          while(headA && ((headA != headB) || (headA->val != headB->val))) {
            headA = headA->next;
            headB = headB->next;
          }
            
          if (!headA) {
              assert(!headB);
              // We consumed both lists, no intersect 
              return nullptr;
          }
        
          result = headA;
          // Advance while equal
          while(headA && headA->val == headB->val) {
            headA = headA->next;
            headB = headB->next;
          }
        }
    
        return result;
    }
};