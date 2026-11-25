// Last updated: 11/25/2026, 3:42:19 PM
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p = head->next;
        ListNode* prev = head;
        vector<int>ans(2,-1);
        ans[0] = INT_MAX;
        int maxDis = INT_MIN,minDis = INT_MAX;
        int firstCritical = -1;
        bool first = true;
        int index = 1;
        int prevCritical = 0;
        while(p->next!=nullptr){
            if((prev->val > p->val && p->next->val > p->val) || 
            (prev->val < p->val && p->next->val < p->val)){
                
                if(first){
                    firstCritical = index;
                    first = false;
                }
                if(prevCritical != 0)ans[0] = min(ans[0],index - prevCritical);
                ans[1] = max(ans[1],index - firstCritical);
                prevCritical = index;
            }
            prev = p;
            p = p->next;
            index++;
        }
        if(ans[0] == INT_MAX)return {-1,-1};
        return ans;
    }
};