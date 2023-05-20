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
    ListNode* swapPairs(ListNode* head) {
      ListNode *dummy = head; // pointer to the head of the linked list

      // swap the values of the nodes
      while (dummy && dummy -> next){
        int temp = dummy -> val; // temporary variable to store the value of the node

        // swap the values
        dummy -> val = dummy -> next -> val;
        dummy -> next -> val = temp;
        
        // move the pointer
        dummy = dummy -> next -> next;
      }
      
      // return the head of the linked list
      return head;
    }
};