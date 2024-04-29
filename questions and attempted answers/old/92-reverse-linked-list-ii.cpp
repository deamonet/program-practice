/*
92. 反转链表 II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/


#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *List_TailInsert(ListNode *&L, vector<int> arr)
{ //正向建立单链表
    L = (ListNode *)malloc(sizeof(ListNode));
    ListNode *t, *r = L;
    for (int i = 0; i < arr.size(); i++)
    {
        //为表尾指针
        //输入结点的值
        //输入9999 表示结束
        t = (ListNode *)malloc(sizeof(ListNode));
        t->val = arr[i];
        r->next = t;
        r = t;
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
        {
            return head;
        };

        ListNode *p, *q, *s, *pre, *temp;
        int pos = 1;
        ListNode *virtual_head = new ListNode(0);
        virtual_head->next = head;
        while (head != NULL)
        {
            cout << "head   " << head->val << "  end\n";
            if (pos == 1 && m == 1)
            {
                cout << "YES1\n";
                p = virtual_head;
            }
            else if (pos == m - 1)
            {
                cout << "YES2\n";
                p = head;
            }

            if (pos == n)
            {
                cout << "YES3\n";
                q = head;
                s = head->next;
                cout << "q" << q->val << "  end\n";
            }

            temp = head->next;
            if (pos > m && pos <= n)
            {
                head->next = pre;
                pre = head;
            }
            pre = head;
            head = temp;
            pos++;
        }

        cout << "YES5\n";
        cout << "p" << p->val << "  end\n";
        cout << "q" << q->val << "  end\n";
        // cout << "s" << s->val << "  end\n";
        p->next->next = s;
        p->next = q;

        return virtual_head->next;
    }
};

//初始化一个链表
int main()
{
    static const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // static const int arr[] = {1};
    // static const int arr[] = {};
    // static const int arr[] = {1, 2};
    // static const int arr[] = { 1, 2, 3, 4 };
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ListNode *head;
    head = List_TailInsert(head, vec); //带头指针
    head = head->next;
    showLinkList(head);
    Solution t;
    int m = 1, n = 2;
    head = t.reverseBetween(head, m, n);
    showLinkList(head);
    return 0;
}