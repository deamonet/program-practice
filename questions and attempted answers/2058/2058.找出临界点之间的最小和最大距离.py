#
# @lc app=leetcode.cn id=2058 lang=python3
#
# [2058] 找出临界点之间的最小和最大距离
#

from typing import Optional, List
from random import randint

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start
# Definition for singly-linked list.
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        res = [-1, -1]
        pos = [0, 0]
        time = 1
        cnt = 0
        last = head
        isLastLarger = last.next.val < last.val
        isLastEqual = last.next.val == last.val

        while last.next.next != None:
            isNextSmaller = last.next.val > last.next.next.val
            isNextEqual = last.next.val == last.next.next.val
            if ((isLastLarger and not isNextSmaller) or (not isLastLarger and isNextSmaller)) and not isNextEqual and not isLastEqual:
                print(cnt)
                if time == 1:
                    pos[0] = cnt
                    time = 2
                elif time == 2:
                    res[0] = cnt - pos[0]
                    res[1] = cnt - pos[0]
                    pos[1] = cnt
                    time = 3
                else:
                    if res[0] > cnt - pos[1]:
                        res[0] = cnt -pos[1]
                    
                    pos[1] = cnt
                    res[1] = pos[1] - pos[0]

            last = last.next
            isLastLarger = isNextSmaller
            isLastEqual = isNextEqual
            cnt+=1
            
        return res
# @lc code=end

def listTolistNode(lst):
    head = ListNode(0, None)
    node = head
    for i in lst:
        node.next = ListNode(i, None)
        node = node.next
    return head.next

def listNodeToList(listNode):
    lst = []
    while listNode != None:
        lst.append(listNode.val)
        listNode = listNode.next
    return lst

if __name__ == "__main__":
    a = [2,2,2,2,2]
    a = listTolistNode(a)
    s = Solution()
    l = s.nodesBetweenCriticalPoints(a)
    print("===========")
    print(l)

