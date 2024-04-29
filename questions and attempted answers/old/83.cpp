/*
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode, *LinkList;
*/

ListNode *List_HeadInsert(ListNode *&L, vector<int> arr)
{
    //逆向建立单链表
    ListNode *s;
    L = (ListNode *)malloc(sizeof(ListNode)); //创建头结点
    L->next = NULL;                           //初始为空链表
    for (int i = 0; i < arr.size(); i++)
    {
        //输入9999 表示结束
        s = (ListNode *)malloc(sizeof(ListNode)); //创建新结点①
        s->val = arr[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

ListNode *List_TailInsert(ListNode *&L, vector<int> arr)
{ //正向建立单链表
    L = (ListNode *)malloc(sizeof(ListNode));
    ListNode *s, *r = L;
    for (int i = 0; i < arr.size(); i++)
    {
        //为表尾指针
        //输入结点的值
        //输入9999 表示结束
        s = (ListNode *)malloc(sizeof(ListNode));
        s->val = arr[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
    //指向新的表尾结点
    //尾结点指针置空
}

void showLinkList(ListNode *head)
{
    //head = head->next;
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        else if (head->next == NULL)
        {
            return head;
        };

        ListNode *p = head;
        ListNode *q = head->next;
        int cnt = 0, pos = 0;
        while (q != NULL)
        {
            if (p->val == q->val)
            {
                cnt++;
                q = q->next;
                if (q == NULL){p->next = NULL;};
                //if (q == NULL && pos == 0){return NULL;};
            }
            else if (p->val != q->val && cnt > 0)
            {
                p->next = q;
                p = q;
                //if (pos == 0){head = q;};
                q = q->next;
                cnt = 0;
            }
            else
            {
                p = p->next;
                q = q->next;
                pos++;
            }
        }
        return head;
    }
};

int main()
{
    //static const int arr[] = {1, 1, 2, 2};
    static const int arr[] = {1, 2, 2};
    //static const int arr[] = {1, 1};
    //static const int arr[] = { 1, 1, 1, 2, 3 };
    //static const int arr[] = {1, 2, 3, 3, 3,4, 4, 4, 5, 5, 5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ListNode *L;
    L = List_TailInsert(L, vec);
    L = L->next;
    showLinkList(L);
    Solution s;
    L = s.deleteDuplicates(L);
    showLinkList(L);
    return 1;
}




//别人家的优秀解法

/*
递归套路解决链表问题：

找终止条件：当head指向链表只剩一个元素的时候，自然是不可能重复的，因此return
想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
每一步要做什么：宏观上考虑，此时head.next已经指向一个去重的链表了，
而根据第二步，我应该返回一个去重的链表的头节点。
因此这一步应该做的是判断当前的head和head.next是否相等，
如果相等则说明重了，返回head.next，否则返回head
如果独立写递归函数有困难的，可以参考一下我写的一个博客，附有详细的图文介绍：
博客链接 https://lyl0724.github.io/2020/01/25/1/
*/
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        head.next = deleteDuplicates(head.next);
        if(head.val == head.next.val) head = head.next;
        return head;
    }
}

//别人家的优秀解法2 C语言
//执行用时 : 4 ms , 在所有 C 提交中击败了 97.33% 的用户 内存消耗 : 6 MB , 在所有 C 提交中击败了 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *p = head;

    while (p != NULL && p->next != NULL)
    {
        if (p->val == p->next->val)
        {
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }
    return head;
}

/*
作者：2020-k
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/solution/zhi-xing-yong-shi-4-ms-zai-suo-you-c-ti-jiao-zh-72/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


//官方解法 java
/*
删除排序链表中的重复元素
力扣 (LeetCode)
发布于 2 年前
34.5k
方法：直接法
算法

这是一个简单的问题，仅测试你操作列表的结点指针的能力。由于输入的列表已排序，因此我们可以通过将结点的值与它之后的结点进行比较来确定它是否为重复结点。如果它是重复的，我们更改当前结点的 next 指针，以便它跳过下一个结点并直接指向下一个结点之后的结点。
*/
public ListNode deleteDuplicates(ListNode head) {
    ListNode current = head;
    while (current != null && current.next != null) {
        if (current.next.val == current.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }
    return head;
}
/*
复杂度分析

时间复杂度：O(n)O(n)，因为列表中的每个结点都检查一次以确定它是否重复，
所以总运行时间为 O(n)O(n)，其中 nn 是列表中的结点数。

空间复杂度：O(1)O(1)，没有使用额外的空间。

正确性

我们可以通过定义循环不变式来证明此代码的正确性。
循环不变式是在循环的每次迭代之前和之后为真的条件。
在这种情况下，一个帮助我们证明正确性的循环不变式是这样的：

列表中直到指针 current 的所有结点都不包含重复的元素。

我们可以用归纳法证明这种情况确实是循环不变式。在进入循环之前，current 指向列表的头部。因此，列表中直到 current 的部分只包含头部。因此它不能包含任何重复的元素。现在假设current 现在指向列表中的某个结点（但不是最后一个元素），并且列表中直到 current 的部分不包含重复元素。在另一个循环迭代之后，发生两件事之一。

current.next 是 current 的副本。在这种情况下，删除 current.next 中的重复结点，并且current保持指向与之前相同的结点。因此，情况仍然成立；一直到 current 仍然没有重复项。

current.next 不是 current 的副本（并且，因为列表已经排序，current.next 也不是 current 之前出现的任何其他元素的副本）。在这种情况下，current 向前移动一步指向 current.next。因此，情况仍然成立；一直到 current 仍然没有重复项。

在循环的最后一次迭代中，current 必定指向最后一个元素，因为再往后，current.next = null。因此，在循环结束后，直到最后一个元素的所有元素都不包含重复项。


评论区：
超长链表情况下，官方题解会产生大量野指针，这里要清除置空一下
（但是这是java 而不是C，所以似乎只是并不是野指针的问题，而是垃圾变量没有被回收）
*/
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while(cur != null && cur.next != null){
            if(cur.val == cur.next.val){
                ListNode node = cur.next; 
                cur.next = node.next;
                node.next = null;//清除野指针
            }else{
                cur = cur.next;          
            }
            
        }
        return head;
    }
}