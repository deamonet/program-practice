/*
 * @lc app=leetcode.cn id=733 lang=java
 *
 * [733] 图像渲染
 *
 * https://leetcode-cn.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (58.03%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    103.4K
 * Total Submissions: 178.2K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。
 * 
 * 你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。
 * 
 * 为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上
 * 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上
 * 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。
 * 
 * 最后返回 经过上色渲染后的图像 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: image = [[1,1,1],[1,1,0],[1,0,1]]，sr = 1, sc = 1, newColor = 2
 * 输出: [[2,2,2],[2,2,0],[2,0,1]]
 * 解析: 在图像的正中间，(坐标(sr,sc)=(1,1)),在路径上所有符合条件的像素点的颜色都被更改成2。
 * 注意，右下角的像素没有更改为2，因为它不是在上下左右四个方向上与初始点相连的像素点。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
 * 输出: [[2,2,2],[2,2,2]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * m == image.length
 * n == image[i].length
 * 1 <= m, n <= 50
 * 0 <= image[i][j], newColor < 2^16
 * 0 <= sr < m
 * 0 <= sc < n
 * 
 * 
 */
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
// @lc code=start
class Solution {
    public static void main(String[] args){
        int[][] image = {{1,1,1},{1,1,0},{1,0,1}};
        int sr = 1;
        int sc = 1;
        int newColor = 2;
        int[][] ret = floodFill(image, sr, sc, newColor);
        System.out.println(Arrays.deepToString(ret));
    }

    public static int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        bfs(sr, sc, image[sr][sc], newColor, image);
        return image;
    }

    public static void dfs(int r, int c, int originColor, int newColor, int[][] image){
        if (image[r][c] != originColor){return;}

        image[r][c] = newColor;

        int[] rows    = {Math.max(0, r-1), Math.min(   image.length-1, r+1)};
        int[] columns = {Math.max(0, c-1), Math.min(image[0].length-1, c+1)};

        for (int row : rows   ){bfs(row, c, originColor, newColor, image);}
        for (int col : columns){bfs(r, col, originColor, newColor, image);}
    }

    public static void bfs(int r, int c, int originColor, int newColor, int[][] image){
        int[] root = {r, c};
        int rt, ct;
        int[] pixel;
        int[] directions = {1, -1};
        Queue<int[]> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()){
            pixel = queue.poll();
            System.out.println(Arrays.toString(pixel));
            rt = pixel[0]; ct = pixel[1];
            
            if (image[rt][ct] == originColor){image[rt][ct] = newColor;}
            else{continue;}

            for (int direct : directions){
                if (rt + direct >= 0 && rt + direct < image.length){
                    pixel[0] = rt + direct;
                    pixel[1] = ct;
                    queue.add(pixel.clone());
                }
                if (ct + direct >= 0 && ct + direct < image[0].length){
                    pixel[0] = rt;
                    pixel[1] = ct + direct;
                    queue.add(pixel.clone());
                }
            }
        }
    }
}
// @lc code=end