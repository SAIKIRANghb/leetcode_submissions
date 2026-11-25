// Last updated: 11/25/2026, 3:48:45 PM
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr; // If the list is empty
        
        ListNode *slow = head, *fast = head;
        
        // Detect the loop using Floyd’s cycle-finding algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Loop detected
            if (slow == fast) {
                // Calculate the length of the loop
                ListNode *temp = head;
                while (temp != fast) {
                    temp = temp->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        
        // No loop
        return nullptr;
    }
};