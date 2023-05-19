
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
    // reverse the linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
      
      int ans = 0; // to store the maximum sum of the pair
      ListNode* slow = head; // slow pointer
      ListNode* fast = head; // fast pointer

      // find the middle of the linked list
      while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
      }

      // reverse the second half of the linked list
      ListNode* head2 = reverse(slow);

      // find the maximum sum of the pair
      while(head != NULL && head2 != NULL){
        ans = max(ans, head->val + head2->val);
        head = head->next;
        head2 = head2->next;
      }
      
      // return the maximum sum of the pair
      return ans;
    }
};