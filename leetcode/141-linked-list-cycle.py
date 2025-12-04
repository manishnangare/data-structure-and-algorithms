# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        front = head
        back = head

        if head == None:
            return False
        
        while front != None and back != None:
            back = back.next

            if front.next == None:
                return False
            
            front = front.next.next

            if front == back:
                return True

        return False