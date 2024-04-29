#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#

# @lc code=start
# Definition for singly-linked list.
# from typing import Optional
# from random import randint

# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 == None:
            return None
        elif list1 == None:
            return list2
        elif list2 == None:
            return list1
        else:
            head = ListNode(0, None)
            tail = ListNode(0, None)
            node = ListNode(0, None)
            if list1.val >= list2.val:
                max = list1
                tail = list2
                node = list2.next
            else:
                max = list2
                tail = list1        
                node = list1.next

            head.next = tail
            while node != None:
                if max.val >= node.val:
                    tail.next = node
                    tail = node
                    node = node.next
                else:
                    tail.next = max
                    tail = max
                    max = node
                    node = tail.next

            tail.next = max
            return head.next
# @lc code=end

def listTolistNode(lst):
    head = ListNode(0, None)
    node = head
    for i in lst:
        node.next = ListNode(i, None)
        node = node.next
        # print(node.val, end=",")

    # print("\n")
    return head.next

def listNodeToList(listNode):
    lst = []
    while listNode != None:
        # print(listNode.val, end=",")
        lst.append(listNode.val)
        listNode = listNode.next

    # print("\n")
    return lst


def merge(a, b):
    a = listTolistNode(a)
    b = listTolistNode(b)
    s = Solution()
    n = s.mergeTwoLists(a, b)
    return listNodeToList(n)


if __name__ == "__main__":
    a = [1, 2, 4]
    b = [1, 3, 4]
    print(a)
    print(b)
    print(merge(a, b))

    a = sorted([randint(1, 100) for _ in range(50)])
    b = sorted([randint(1, 100) for _ in range(50)])
    print(a)
    print(b)
    print(merge(a, b))
    