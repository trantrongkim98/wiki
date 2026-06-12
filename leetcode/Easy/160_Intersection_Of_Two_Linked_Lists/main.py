from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        if headA is None or headB is None:
            return None
        nodeA = headA
        nodeB = headB
        while nodeA != nodeB:
            if nodeA is None:
                nodeA = headB
            else:
                nodeA = nodeA.next
                
            if nodeB is None:
                nodeB = headA
            else:
                nodeB = nodeB.next
        return nodeA


def build_list(arr):
    dummy = ListNode(0)
    curr = dummy
    for v in arr:
        curr.next = ListNode(v)
        curr = curr.next
    return dummy.next, curr  # head + tail
# build riêng
headA, tailA = build_list([4, 1])
headB, tailB = build_list([5, 6, 1])
# build phần chung
common, _ = build_list([8, 4, 5])
tailA.next = common
tailB.next = common

s = Solution()
print(s.getIntersectionNode(headA, headB).val)
