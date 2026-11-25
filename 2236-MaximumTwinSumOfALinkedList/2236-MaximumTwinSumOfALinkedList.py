# Last updated: 11/25/2026, 3:42:13 PM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        if head == None:
            return -1
        mp: Dict[int,ListNode] = {}

        cnt: int = 0

        ptr: ListNode = head

        while ptr != None:
            mp[cnt] = ptr 
            ptr = ptr.next
            cnt = cnt + 1

        maxSum: int = 0

        for i in range(0,cnt):
            maxSum = max(mp[cnt - 1 - i].val + mp[i].val, maxSum)

        return maxSum

        