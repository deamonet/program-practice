import java.util.Queue;

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
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Queue<int[]> queue = new LinkedList<>();

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    queue.offer(new int[] {i, j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }
        
        int[][] directions = new int[][]{{0,0,1,-1},{1,-1,0,0}};
        while (!queue.isEmpty()){
            int[] xy = queue.poll();
            int x=xy[0], y=xy[1];
            for (int i=0; i<4; i++){
                int newx = x+directions[0][i];
                int newy = y+directions[1][i];
                if (newx>=0 && newx<m && newy>=0 && newy<n && mat[newx][newy]==-1){
                    mat[newx][newy] = mat[x][y] + 1;
                    queue.offer(new int[]{newx, newy});
                }
            }
        }
        return mat;
    }
}
// @lc code=end

