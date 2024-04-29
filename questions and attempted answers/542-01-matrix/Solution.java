/*
 * @lc app=leetcode.cn id=542 lang=java
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (46.05%)
 * Likes:    668
 * Dislikes: 0
 * Total Accepted:    97.1K
 * Total Submissions: 210.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
 * 
 * 两个相邻元素间的距离为 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：[[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
 * 输出：[[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 
 * 1 
 * mat[i][j] is either 0 or 1.
 * mat 中至少有一个 0 
 * 
 * 
 */

// @lc code=start
import java.util.LinkedList;
import java.util.Arrays;


class Solution {
    
    static boolean[][] used = new boolean[10000][10000];
    static int[] directions = {1, -1};

    public static void main(String[] args){
        int[][] mat = {{0,0,0},{0,1,0},{0,0,0}};
        int[][] ret = updateMatrix(mat);
        System.out.println(Arrays.deepToString(ret));
    }

    public static int[][] updateMatrix(int[][] mat) {
        for(int i=0; i<mat.length; i++){
            for(int j=0; j<mat[0].length; j++){
                used[i][j] = false;
            }
        }
        for (int x=0; x<mat.length; x++){
            for (int y=0;  y<mat[0].length; y++){
                if (!used[x][y]){
                    mat = dfs(x, y, mat);
                }
            }
        }
        return mat;
        
    }
    public static int[][] dfs(int x, int y, int[][] mat){
        if (mat[x][y] == 0){
            return mat;
        }
        used[x][y] = true;
        int newx, newy;
        LinkedList<Integer> newxs = new LinkedList<>();
        LinkedList<Integer> newys = new LinkedList<>();
        for (int direct : directions){
            if(x + direct >= 0 && x + direct < mat.length)
            {
                if(!used[x+direct][y]){
                    newx = x + direct;
                    newy = y;
                    newxs.add(newx);
                    newys.add(newy);    
                }
            }
            if (y + direct >= 0 && y + direct < mat[0].length){
                if(!used[x][y+direct]){
                    newx = x;
                    newy = y + direct;
                    newxs.add(newx);
                    newys.add(newy);
                }
            }        
        }
        int ret = 100000000;
        for (int i = 0, j=0; i < newxs.size() || j < newys.size(); i++, j++) {
            newx = newxs.get(i);
            newy = newys.get(i);
            mat = dfs(newx, newy, mat);
            if (mat[newx][newy] < ret){
                ret = mat[newx][newy];
            }
        }
        mat[x][y] = ret + 1;
        return mat;
    }
}
// @lc code=end