// Last updated: 11/25/2026, 3:42:00 PM
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
    int sum = 0;
    ListNode* root;
    ListNode* merge(ListNode* head,ListNode* prev0 , int sum){
        if(head == nullptr){
            return nullptr;
        }
        if(head->val == 0){
            ListNode* New = new ListNode(sum);
            prev0->next = New;
            New->next = head->next;
            prev0 = New;
            sum = 0;
            head = New;
        }
        head->next = merge(head->next,prev0,sum + head->val);
        return head;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev0 = head;
        ListNode* p = head->next;
        int sum = 0;
        while(p!=nullptr){
            if(p->val == 0){
                ListNode* New = new ListNode(sum);
                prev0->next = New;
                New->next = p->next;
                prev0 = New;
                sum = 0;
            }
            sum += p->val;
            p = p->next;
        }
        return head->next;
    }
};