# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum = 0
        carry = 0
        result = ListNode(0)
        nextNode = result

        while l1 != None and l2 != None:
            sum = l1.val + l2.val+ carry
            carry = int(sum/10)
            sum = sum%10

            temp = ListNode(sum)
            nextNode.next = temp
            nextNode = temp

            l1 = l1.next
            l2 = l2.next
        
        while l1 != None:
            sum = l1.val + carry
            carry = int(sum/10)
            sum = sum%10

            temp = ListNode(sum)
            nextNode.next = temp
            nextNode = temp

            l1 = l1.next
        
        while l2 != None:
            sum = l2.val + carry
            carry = int(sum/10)
            sum = sum%10

            temp = ListNode(sum)
            nextNode.next = temp
            nextNode = temp

            l2 = l2.next

        if carry != 0:
            temp = ListNode(carry)
            nextNode.next = temp
        
        return result.next