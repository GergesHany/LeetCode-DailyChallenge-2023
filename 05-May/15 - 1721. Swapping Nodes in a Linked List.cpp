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
    ListNode* swapNodes(ListNode* head, int k) {
      
      vector < int > v; // vector to store the values of the linked list
      
      // store the values of the linked list in the vector
      ListNode *cur = head;
      while (cur){
        v.push_back(cur->val);
        cur = cur->next;
      }

      // swap the values
      swap(v[k - 1], v[int(v.size()) - k]);
      
      // store the values back in the linked list
      cur = head;
      for (auto &x : v){
        cur->val = x;
        cur = cur->next;
      }

      // return the head of the linked list
      return head;
    }
};