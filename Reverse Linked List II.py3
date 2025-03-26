#Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head  
        
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        
        for _ in range(left - 1):
            prev = prev.next

      
        current = prev.next
        next_node = None

        for _ in range(right - left):
            next_node = current.next
            current.next = next_node.next
            next_node.next = prev.next
            prev.next = next_node

        return dummy.next
