#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>


using namespace std;


void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    for (int i = 0; i < count; i++)
    {
        cout << valList[i] << "\t";
    };
    cout << "\n";
}

void Show2Vec(const vector<vector<int>> &vallist2)
{
    int count = vallist2.size();
    for (int i = 0; i < count; i++)
    {
        cout << "\n";
        ShowVec(vallist2[i]);
    }
}


// 新版本的show vec
void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    cout << "[ ";
    for (int i = 0; i < count; i++)
    {
        if (i == count - 1)
        {
            cout << valList[i];
        }
        else
        {
            cout << valList[i] << ", ";
        }
    };
    cout << " ]";
}

void Show2Vec(const vector<vector<int>> &vallist2)
{
    cout << "[\n ";
    int count = vallist2.size();
    for (int i = 0; i < count; i++)
    {
        cout << "\t";
        ShowVec(vallist2[i]);
        if (i < count - 1)
        {
            cout << ", ";
        }
        cout << "\n";
    }
    cout << " ]\n";
}


int main(){
    Solution s;
    vector<int> nums;
    vector<vector<int>> data;
    int rows = 3, cols = 3;
    for(int j=0; j<rows; j++){
        nums.clear();
        for(int i=0;i<cols;i++){
            nums.push_back(i+cols*j);
        };
        data.push_back(nums);
    };
    Show2Vec(data);
    cout<<"\n\n";
    ShowVec(s.spiralOrder(data));
}



// 最优雅的方式初始化一个vector

//I can create an array and initialize it like this:

int a[] = {10, 20, 30};

//How do I create a std::vector and initialize it similarly elegant?

//The best way I know is:

std::vector<int> ints;

ints.push_back(10);
ints.push_back(20);
ints.push_back(30);

//Is there a better way?
//c++ vector stl initialization


//One method would be to use the array to initialize the vector

static const int arr[] = {16,2,77,29};
vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

// 链表

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode, *LinkList;

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


//初始化一个链表
int main()
{
    static const int arr[] = {16, 2, 77, 29};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ListNode *head;
    head = List_TailInsert(head, vec); //带头指针
    head = head->next;
    showLinkList(head);
    return 0;
}


// 二叉树

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 按顺序创建一个二叉树

#include <queue>

TreeNode *create_binary_tree(vector<int> elements)
{
    int sum = 0;
    vector<int> frame;
    for(int i=0; i<=elements.size(); i++)
    {
        sum = sum + 2^i;
        if (sum >= elements.size()){break;}
        frame.push_back(2^i);
    }
    frame.push_back(elements.size()-sum);

    TreeNode *root = new TreeNode(elements[0]);
    vector<TreeNode *> upper_que;
    vector<TreeNode *> new_upper_que;
    upper_que.push_back(root);
    int sum=1;
    for (int j=1; j<frame.size(); j++)
    {
        vector<TreeNode *> que;
        for (int i = 0; i<frame[j]; i++)
        {
            TreeNode *node = new TreeNode(elements[sum+i]);
            for (int n=0; n<upper_que.size(); n++)
            {
                if (n%2==0)
                {
                    upper_que[n]->left = node;
                }
                else
                {
                    upper_que[n]->right = node;
                }
            }
            new_upper_que.push_back(node);
        }
        upper_que.clear();
        upper_que = new_upper_que;
        new_upper_que.clear();
    }
    return root;
}

int main(void)
{
    static const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::const_iterator first = vec.begin() + 3;
    vector<int>::const_iterator last = vec.begin() + 6;
    vector<int> subvec(first, last);
    ShowVec(vec);
    cout << "\n\n";
    ShowVec(subvec);
}