import java.util.List;

/*
 * @lc app=leetcode.cn id=542 lang=java
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (46.12%)
 * Likes:    676
 * Dislikes: 0
 * Total Accepted:    98.5K
 * Total Submissions: 213.5K
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
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int x;
        int y;
        int[][] directions = new int[][]{{0, 0, -1, 1}, {-1, 1, 0, 0}};

        Queue<Integer> xs = new LinkedList<Integer>();
        Queue<Integer> ys = new LinkedList<Integer>();
        for (x=0; x<m; x++){
            for (y=0; y<n; y++){
                if (mat[x][y] == 0){
                    xs.offer(x);
                    ys.offer(y);
                } else {
                    mat[x][y] = -1;
                }
            }
        }

        while (!xs.isEmpty()){
            x = xs.poll();
            y = ys.poll();
            for (int i=0; i<4; i++){
                int nx = x+directions[0][i];
                int ny = y+directions[1][i];
                if ( nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == -1){
                    xs.offer(new Integer(nx));
                    ys.offer(new Integer(ny));
                    mat[nx][ny] = mat[x][y] + 1;
                }
            }
        }
        return mat;
    }
}
// @lc code=end

