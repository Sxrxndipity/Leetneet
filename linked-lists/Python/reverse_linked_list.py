class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode[ListNode]) -> ListNode[ListNode]:
        temp, prev = head, None
        while (temp):
            nxt = temp.next
            temp.next = prev
            prev = temp
            temp = nxt
        return prev
