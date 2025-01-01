class ll:

    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class MyLinkedList:

    def __init__(self):
        self.left = ll(0)
        self.right = ll(0)
        self.left.next = self.right
        self.right.prev = self.left

    def get(self, index: int) -> int:
        cur = self.left.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        if cur and cur != self.right and index == 0:
            return cur.val
        return -1

    def addAtHead(self, val: int) -> None:
        node, pre, nxt = ll(val), self.left, self.left.next
        pre.next = node
        node.prev = pre
        nxt.prev = node
        node.next = nxt

    def addAtTail(self, val: int) -> None:
        node, pre, nxt = ll(val), self.right.prev, self.right
        pre.next = node
        node.prev = pre
        nxt.prev = node
        node.next = nxt

    def addAtIndex(self, index: int, val: int) -> None:
        cur = self.left.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        if cur and index == 0:
            node, pre, nxt = ll(val), cur.prev, cur
            pre.next = node
            node.prev = pre
            nxt.prev = node
            node.next = nxt

    def deleteAtIndex(self, index: int) -> None:
        cur = self.left.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        if cur and cur != self.right and index == 0:
            pre, nxt = cur.prev, cur.next
            pre.next = nxt
            nxt.prev = pre
