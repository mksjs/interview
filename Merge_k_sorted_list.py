"""Merge K Sorted Lists

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20 """

#-----------------------------------------------------------------------------------------------------------------------------------------------#-----------------------------------------------------------------------------------------------------------------------------------------------



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from Queue import PriorityQueue
class Solution:
    # @param A : list of linked list
    # @return the head node in the linked list
    def mergeKLists(self, A):
        
        
        head =point =ListNode(0)
        
        q =PriorityQueue();
        
        for l in A:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val , node =q.get()
            point.next = ListNode(val)
            point=point.next
            node =node.next
            if node:
                q.put((node.val,node))
        return head.next

