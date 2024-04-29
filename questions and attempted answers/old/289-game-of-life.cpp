/*
289. 生命游戏
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

 

示例：

输入： 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 

进阶：

你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。l
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;


// 思路：
// 1. 创建一个二维表格，记录所有生命的周围生命的信息
// 2. 遍历整个二维表格，遇到1即给周围的8个生命的周围生命信息加一；遇到0不变。
// 3. 根据步骤1的二维表格更改确定当前生命是否死亡。

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




class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        if(m==0){return;}
        
        int n = board[0].size();
        
        if(n==0){return;}

        cout << "m " << m;
        cout << "\tn " << n << "\n\n";
        int temp_x, temp_y;

        vector<vector<int>> directions;
        vector<int> temp_row;
        temp_row.clear();
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                temp_row.clear();
                if (x == 1 && y == 1)
                {
                    continue;
                }
                temp_row.push_back(x - 1);
                temp_row.push_back(y - 1);
                directions.push_back(temp_row);
            }
        }


        // vector 容器的构造器，不填第二个参数默认为0
        vector<vector<int>> data(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    for(int x=0; x<directions.size(); x++)
                    {
                        temp_x = i+directions[x][0];
                        temp_y = j+directions[x][1];
                        if(temp_x < 0 || temp_x > m -1){continue;}
                        if (temp_y < 0 || temp_y > n - 1)
                        {
                            continue;
                        }
                        data[temp_x][temp_y]++;
                    }

                }
            }
        }
        Show2Vec(data);

        for (int i = 0; i < m; i++)
        {
            for (int j=0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    if (data[i][j] < 2)
                    {
                        board[i][j] = 0;
                    }
                    else if (data[i][j] > 3)
                    {
                        board[i][j] = 0;
                    }
                }
                else
                {
                    if (data[i][j] == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};


int main()
{
    // vector<vector<int>> vec = {
    //     {0, 1, 0},
    //     {0, 0, 1},
    //     {1, 1, 1},
    //     {0, 0, 0}
    // };
    // vector<vector<int>> vec = {
    //     {0, 1, 0},
    //     {0, 0, 1},
    //     {1, 1, 1},
    //     {0, 0, 0}
    // };

    vector<vector<int>> vec = {{1}};

    Show2Vec(vec);
    Solution s;
    s.gameOfLife(vec);
    Show2Vec(vec);
}


// 看看别人的邪淫奇技
// 其实跟我的思路差不多，就是计算每一个生命的周围生命的数量
// 当然区别在于这个解答很好的利用了C++的位运算和int 类型有32个bit的4个字节的存储量的性质
// 位运算就是直接对二进制数运算的技巧，包括 & | ~ ^ % >> <<



/*
C++ 位运算原地操作，击败双百。
前额叶没长好
发布于 1 天前
3.9k
一个 int 有 32 bit，输入数据只用了一个 bit，所以我们可以利用其他空闲的bit位进行“原地修改”。
具体的位运算操作可以查看代码注释。
*/



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                int sum = 0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                        sum += (board[nx][ny]&1); // 只累加最低位
                    }
                }
                if(board[i][j] == 1) {
                    if(sum == 2 || sum == 3) {
                        board[i][j] |= 2;  // 使用第二个bit标记是否存活
                    }
                } else {
                    if(sum == 3) {
                        board[i][j] |= 2; // 使用第二个bit标记是否存活
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1; //右移一位，用第二bit覆盖第一个bit。
            }
        }
    }
};
