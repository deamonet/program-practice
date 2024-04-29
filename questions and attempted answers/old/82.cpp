/*
82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/


#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>

using namespace std;

// Definition for singly-linked list.
/*
struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
*/

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode, *LinkList;


ListNode * List_HeadInsert(ListNode * &L, vector<int> arr)
{
    //逆向建立单链表
    ListNode *s;
    L = (ListNode *)malloc(sizeof(ListNode)); //创建头结点
    L->next = NULL;                      //初始为空链表
    for(int i=0; i<arr.size(); i++)
    {
        //输入9999 表示结束
        s = (ListNode *)malloc(sizeof(ListNode)); //创建新结点①
        s->val = arr[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

ListNode * List_TailInsert(ListNode * &L, vector<int> arr)
{          //正向建立单链表
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
    while(head!=NULL)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head==NULL){return head;}
        else if(head->next==NULL){return head;};

        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *parent = head; 
        //这个parent 指针的定义的确有些多余，在某些情况下，甚至还会导致程序变得更为复杂。
        //直接一开始把p指针设置为parent 就好了。
        int cnt = 0, pos = 0;
        while (q != NULL)
        {
            if (p->val == q->val)
            {
                cnt++;
                q = q->next;
                if(q == NULL){parent->next = NULL;};
                if(q == NULL && pos == 0){return NULL;};
            }
            else if (p->val != q->val && cnt > 0)
            {
                parent->next = q;
                if(pos == 0){head = q;};
                p = q;
                q = q->next;
                cnt = 0;
            }
            else
            {
                parent = p;
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
    //static const int arr[] = {1, 2, 3, 3, 3,4, 4, 4, 5, 5, 5};
    //static const int arr[] = { 1, 1, 1, 2, 3 };
    static const int arr[] = {1, 1};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ListNode * L;
    L = List_TailInsert(L, vec);
    L = L->next;
    showLinkList(L);
    Solution s;
    L = s.deleteDuplicates(L);
    showLinkList(L);
    return 1;
}

/*问题：
a->next = b
如果把 b 修改成 c： b=c
那么为什么 a->next 不等于 c ?
a b c 都是指针变量。
*/