/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    if(head==NULL){cout<<"this link node is null";}
    //head = head->next;
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}


// 思路1：递归。
/* 
终止条件：只剩两个元素
每一层的操作：< < > x（用小于号表示小于x）
            如果新加入的是<，那么不做操作。
            如果新加入的是>，那么彼此交换，直到大于在最后一个<之后。

反正我尝试了多次，这个思路并不成功，难点在于确定最后一个<的位置。
最好的办法其实是遍历，把 > 和 < 分别添加到新的链表，最后把两个链表链接起来即可。
*/

class Solution
{
public:
    ListNode *last_small = new ListNode(0);
    int small_cnt = 0;
    //int recur_depth = 0;

    ListNode *partition(ListNode *head, int x)
    {
        //cout << "depth\t" << recur_depth << "\n";
        //recur_depth++;
        if (head == NULL)
        {
            return head;
        }
        else if (head->next == NULL)
        {
            cout << "yes\n";
            if (head->val >= x)
            {
                if(small_cnt==0)
                {last_small->next = head;last_small->val = -10000;}
                small_cnt = 1;
            }
            else
            {
                last_small = head;
            }
            return head;
        }

        if (head->val < x && head->next->val >= x)
        {
            cout << "yes2\n";
            last_small = head;
            small_cnt = 1;
        }

        if (head->val >= x)
        {
            cout << "yes1\n";
            ListNode *new_head = partition(head->next, x);
            cout << "head\t" << head->val << "\n";
            cout << "new_head\t";
            showLinkList(new_head);
            head->next = last_small->next;
            last_small->next = head; // 实现加入大于的交换。
            cout << "new_head_change\t";
            showLinkList(new_head);
            cout<<"last-next\t";
            showLinkList(last_small);
            if (last_small->val == -10000){return last_small->next;}
            else{return new_head;}
        }
        else
        {
            cout << "yes3\n";
            cout << "head->val\t" << head->val << "\n";
            cout << "head->next->val\t" << head->next->val << "\n";
            cout << "head-next-list\t";
            showLinkList(head->next);
            head->next = partition(head->next, x);
            cout << "head->next = partition(head->next, x)\t";
            showLinkList(head->next);
            return head;
        }
    }
};

int main()
{
    //static const int arr[] = {};
    //static const int arr[] = {1};
    //static const int arr[] = {1, 1};
    //static const int arr[] = {1, 3};
    //static const int arr[] = {1, 2, 2};
    //static const int arr[] = {1, 1, 2, 2};
    //static const int arr[] = { 1, 1, 1, 2, 3 };
    //static const int arr[] = {1, 4, 3, 2, 5, 2};
    //static const int arr[] = {1, 2, 3, 3, 3,4, 4, 4, 5, 5, 5};
    //static const int arr[] = {1, 2, 3, 4, 93};
    //static const int arr[] = {2, 1, 3};
    static const int arr[] = {1,2, 3};
    int x = 2;

    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ListNode *L;
    L = List_TailInsert(L, vec);
    L = L->next;
    cout<<"Head\t"<<L->val<<"\n";
    cout<<"ORIGINAL\t";
    showLinkList(L);
    Solution s;
    L = s.partition(L, x);
    cout << "L->val\t" << L->val << "\n";
    cout<<"RESULT\t\t";
    showLinkList(L);
    return 1;
}