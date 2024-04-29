#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void show_list_node(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode *construct_list_node_backwards(int n)
{
    ListNode *virtual_head = new ListNode(0);
    for (int i = 0; i < n; i++)
    {
        ListNode *node = new ListNode(0);
        node->val = i;
        node->next = virtual_head->next;
        virtual_head->next = node;
    }
    return virtual_head;
}

ListNode *construct_list_node_downwards(int n)
{
    ListNode *virtual_tail = new ListNode(0);
    ListNode *vritual_head = new ListNode(0);
    vritual_head = virtual_tail;
    vritual_head->next = virtual_tail;
    for (int i = 0; i <  n; i++)
    {
        ListNode *node = new ListNode(0);
        node->val = i;
        virtual_tail->next = node;
        virtual_tail = node;
    }
    return vritual_head;
}

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        ListNode *original_head = new ListNode(0);
        ListNode *original_tail = new ListNode(0);
        original_head = head;
        int size = 0;
        int n = 0;
        while (head != NULL)
        {
            if (head->next == NULL)
            {
                original_tail = head;
            }
                head = head->next;
            n++;
        }
        cout<<"n"<<n<<"\n";
        if(n==0){return original_head;}
        else if(n==1){return original_head;}
        else if(k % n == 0){return original_head;}
        else{
        int i = 0;
        cout << "orginal_tal" << original_tail->val << "\n";
        ListNode *new_tail, *new_head = new ListNode(0);
        head = original_head;
        while(head != NULL)
        {
            cout<<"i"<<i<<"\n";
            if ((i + k) % n == n-1)
            {
                new_tail = head;
                new_head = head->next;
                cout<<"head_val"<<new_head->val<<"\n";
            }
            head = head->next;
            i++;
        }
        original_tail->next = original_head;
        //cout << "orginal_tal" << original_tail->val << "\n";
        //cout << "orginal_tal next val" << original_tail->next->val << "\n";
        new_tail->next = NULL;

        //cout << "new head val" << new_head->val << "\n";
        //cout << "new head next next val" << new_head->next->next->val << "\n";

        return new_head;
        }
    }
};


int main()
{
    Solution s;
    int n = 2;
    ListNode *head = construct_list_node_downwards(n);
    head = head->next;
    show_list_node(head);
    int k = 3;
    ListNode *new_head = s.rotateRight(head, k);
    show_list_node(new_head);
}