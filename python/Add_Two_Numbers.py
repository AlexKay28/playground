"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

PS: The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def get_num(v):
    num = ''
    if v.next is None:
        return v.val
    return v.val + get_num(v.next)*10
    
def get_list(vals):
    if len(vals) == 1:
        return ListNode(vals[0])
    elif len(vals) == 2:
        return ListNode(val=vals[0], next=ListNode(vals[1]))
    return ListNode(val=vals[0], next=get_list(vals[1:]))
    
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        n1, n2 = get_num(l1), get_num(l2)
        
        return get_list([int(i) for i in str(n1 + n2)][::-1])
