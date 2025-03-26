#Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

#You should preserve the original relative order of the nodes in each of the two partitions.


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
       
        smaller_head = ListNode(0)
        greater_head = ListNode(0)
        
     
        smaller = smaller_head
        greater = greater_head
        
      
        while head:
            if head.val < x:
                smaller.next = head
                smaller = smaller.next
            else:
                greater.next = head
                greater = greater.next
            head = head.next
        
        #
        greater.next = None  
        smaller.next = greater_head.next  
        
        return smaller_head.next 
