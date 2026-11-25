// Last updated: 11/25/2026, 3:50:06 PM
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (ListNode* list : lists) {
            if (list) pq.push(list); // Only push non-null lists
        }
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            
            if (!head) {
                head = tail = top;  // Initialize head and tail to the first node
            } else {
                tail->next = top;   // Append to the merged list
                tail = tail->next;
            }
            
            if (top->next) pq.push(top->next);  // Push the next node in the list if it exists
        }
        
        return head;
    }
};
