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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;  // Previous node pointer (new tail)
        ListNode *curr = head;     // Current node pointer for traversal
        
        while (curr != nullptr) {
            ListNode *temp = curr->next;  // Temporarily store next node
            curr->next = prev;            // Reverse current node's pointer
            prev = curr;                  // Move prev to current node
            curr = temp;                  // Advance to next node
        }
        
        return prev;  // Prev is the new head of the reversed list
    }
};
