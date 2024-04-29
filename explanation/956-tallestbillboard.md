# 956-最高的广告牌

首先解法是 动态规划

而在这个题目里，关注点不是到当前为止一共“使用”了多少个钢条也就是子问题不再是n-1或者n-k一类。而是当前的高度差。

因为最终该问题的目标是达到高度差为0，所以关键点在于，每增加一个钢条，高度差变化的子问题。

dp[diff] 表示最大高度，diff 表示高度差。

这里有一个问题就是，既然存在高度差，如何判断当前的最大高度？是按短边还是长边算？最后要求的结果是高度差为0，所以长边短边都一样。

如果视作是数字相加减的话，也就是统计正数和合统计负数和是一样的。

看网络上的解法，diff 可以设置成纯**正数**，也可以是负数，这里就用负数，含义就是左边的高度减去右边的高度。

每新增一个铁杆，可以放在左边（+1），也可以放在右边（-1），也可以丢弃（看英文leetcode上最高赞的解答，并没有考虑到丢弃的情况。）

假如第 n 个铁杆长度是 x ，此时的高度差是 a 。更新后的最大高度是 dp[a+x] 或者是 dp[a-x] 又或者是 dp[a]。这次的新生成的暂时最大高度 dp" 就是与 dp[a] 相关的值。

因为正数和就表示最大高度，所以加上就是直接加上。而减去不做变化。

**对于 a+x**  dp" = dp[a] + x

**对于 a-x**  dp" = dp[a]

由于之前可能存在过一个同样高度差的最大高度，所以这里需要把更新的结果跟上一次结果对比。（如果是第一次出现这种高度差，上一次 dp 值设 0）

**状态转移方程**可以描述成：

dp[a+x] = max(dp[a+x], dp[a])
dp[a-x] = max(dp[a-x], dp[a] + x) （也可以把 x 加在上面一行，结果一样，长短边的区别）
dp[a] = dp[a]