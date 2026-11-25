// Last updated: 11/25/2026, 3:50:10 PM
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
   ListNode* helper(ListNode* head,int n,int &cnt){
       if(head==NULL){
           return NULL;
       }
       ListNode* prev=NULL;
       prev=helper(head->next,n,cnt);
       cnt++;
       if(cnt == n){
           return prev;
       }
       head->next = prev;
       return head; 
   }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        return helper(head,n,cnt);
    }
};