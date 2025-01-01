class ListNode(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists or len(lists) == 0:
            return None

        while len(lists) > 1:
            temp = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if i+1 < len(lists) else None
                temp.append(self.merge(l1, l2))
            lists = temp
        return lists[0]


    def merge(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy

        while l1 or l2:
            if l1 and ((not l2) or l1.val < l2.val):
                tail.next = l1
                l1 = l1.next

            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next

        return dummy.next

