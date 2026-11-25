// Last updated: 11/25/2026, 3:44:35 PM
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> umap;
        ListNode* ptr = head;
        int sum = 0;
        
        while (ptr != nullptr) {
            sum += ptr->val;
            if (sum == 0) {
                umap.clear(); 
                head = ptr->next;
            } else {
                if (umap.find(sum) != umap.end()) {
                    ListNode* start = umap[sum]->next;
                    ListNode* temp = start;
                    int tempSum = sum + temp->val;
                    while (temp != ptr) {
                        umap.erase(tempSum);
                        temp = temp->next;
                        tempSum += temp->val;
                    }
                    umap[sum]->next = ptr->next;
                }
                else {
                    umap[sum] = ptr;
                }
            }
            ptr = ptr->next;
        }
        
        return head;
    }
};
