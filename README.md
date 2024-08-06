- 1.两数之和 
    - 哈希表。
- 2.两数相加
    - 链表操作。
    - 注意carry进位的写法。
- 3.无重复字符的最长子串 x
    - 滑动窗口。
- 4.寻找两个正序数组的中位数 x
    - 分治。
    - 注意k-th从1开始取。
- 5.最长回文子串
    - 区间DP。
- 6.Z 字形变换
    - 模拟找规律。
    - 两端的行的每个元素的间隔是固定的。非两端的行可以拆分成两块分别找规律。
- 7.整数反转
    - 转换为正数，然后模拟。
- 8.字符串转换整数 (atoi)
    - 模拟。
- 9.回文数
    - 模拟。
    - 反转一半的数字。当原始数字小于或等于反转后的数字时，就意味着我们已经处理了一半位数的数字了。
- 10.正则表达式匹配 x
    - DP。
    - 读好题，理解\*的含义。要特殊处理“”能匹配"a\*a\*a\*"这种情况。要理解".\*"的情况。
- 11.盛最多水的容器 x
    - 从两边往里的双指针。谁的高度小，谁就往里挪。
    - 这个题不用单调栈，它和第43题不同，它的墙没有厚度，也没有按块分割储水的问题。
- 12.整数转罗马数字
    - 数组模拟。
- 13.罗马数字转整数
    - 按照每个数字和它右边数字的大小关系做模拟。
- 14.最长公共前缀
    - 字典树。
    - 注意要判断树中的节点是否为字符串的结束。
- 15.三数之和
    - 排序+双指针。
    - 枚举第一个数，其余两个在排好序的数组中从两边到中间双指针移动。
- 16.最接近的三数之和
    - 排序+双指针。
    - 枚举第一个数，其余两个在排好序的数组中从两边到中间双指针移动。
- 17.电话号码的字母组合
    - DFS。
- 18.四数之和
    - 排序+双指针。
    - 枚举第一个和第二个数，其余两个在排好序的数组中从两边到中间双指针移动。 
- 19.删除链表的倒数第 N 个结点
    - 递归。
- 20.有效的括号
    - 栈模拟。
- 21.合并两个有序链表
    - 可以用迭代模拟，或者是递归。
- 22.括号生成
    - DFS枚举。记录当前生成的左括号和右括号数量。
- 23.合并 K 个升序链表 x
    - 分治。每次用合并2个升序链表来做。
- 24.两两交换链表中的节点
    - 模拟。
    - 用哨兵节点。
- 25.K 个一组翻转链表
    - 模拟。
    - 用哨兵节点。
- 26.删除有序数组中的重复项
    - 双指针的滑动窗口。
    - 左右指针从开始处滑出数值相同的区间，填到数组中。
- 27.移除元素
    - 双指针，一个在左边另一个在右边，往中间移动。
- 28.找出字符串中第一个匹配项的下标
    - KMP
- 29.两数相除。
    - 相当于把答案二进制编码然后和除数相乘。
    - 注意-INT_MIN无法用int表示，所以都需要转化为负数来做。
- 30.串联所有单词的子串 x
    - 滑动窗口。
    - 由于words的每个单词的长度都相同，可以按照余数分组。对于每一组，用滑动窗口来判断能否找到可行解。
- 31.下一个排列 x
    - 从后向前 查找第一个 相邻升序 的元素对 `(i,j)`，满足 `A[i] < A[j]`。此时 `[j,end)` 必然是降序。
    - 在 `[j,end)` 从后向前 查找第一个满足 `A[i] < A[k]` 的 k。`A[i]`、`A[k]` 分别就是上文所说的「小数」、「大数」。
    - 将 `A[i]` 与 `A[k]` 交换。
    - 可以断定这时 `[j,end)` 必然是降序，逆置 `[j,end)`，使其升序。
    - 如果在步骤 1 找不到符合的相邻元素对，说明当前 `[begin,end) `为一个降序顺序，则直接跳到步骤 4。
- 32.最长有效括号 x
    - DP。
    - `dp[i]`表示从最开始以位置i为结束（必须包括位置i）的最长有效括号长度。
    - 根据i和i-1的括号类型分类讨论。
- 33.搜索旋转排序数组
    - 二分。
    - 数组被分为两个递增段。根据mid和left的大小关系判断在哪个递增段上。
    - 在每个递增段上，根据target和mid、target跟两端的两组大小关系，判断该往哪里二分。
- 34.在排序数组中查找元素的第一个和最后一个位置
    - 二分。
    - 可以用`std::equal_range()`。
- 35.搜索插入位置
    - 二分。
- 36.有效的数独
    - 模拟。判断满足数独的条件。
- 37.解数独
    - 用最朴素的DFS枚举就能过。
- 38.外观序列
    - 递归。
- 39.组合总和
    - DFS做枚举。
- 40.组合总和 II
    - DFS做枚举。
    - 为了去重，需要先给数组排序，并记录每一元素是否visit。访问到`c[idx]`时，如果`c[idx] == c[idx-1]`并且这次枚举没有包括`c[idx-1]`，那么枚举的结果肯定在之前被得到了，可以忽略这次枚举。
- 41.缺失的第一个正数
    - 原地哈希。
    - 把负数设为数组的长度+1。然后原地哈希，用负值表示哈希有值。
- 42.接雨水 x
    - 单调栈。
    - 维护单调递减的栈，如果遇到比栈顶高的元素，就弹出一个元素，并用三根柱子计算接了多少水。
- 43.字符串相乘
    - 大整数乘法。
    - 注意输出的时候用flag忽略前导0。
- 44.通配符匹配 x
    - DP。`dp[i][j]`表示`s[0...i)`和`p[0...j)`能否匹配。
    - 初始化时预先处理`p="*****"`的情况。
- 45.跳跃游戏 II
    - 贪心。
    - 每次从当前能选择的集合中尝试跳到最远的位置。
    - 注意`[0]`的情况和是否能正好跳到边界。
- 46.全排列
    - DFS枚举。
- 47.全排列 II
    - DFS枚举。
    - 为了去重，需要先给数组排序，并记录每一元素是否visit。访问到`nums[idx]`时，如果`nums[idx] == nums[idx-1]`并且这次枚举没有包括`nums[idx-1]`，那么枚举的结果肯定在之前被得到了，可以忽略这次枚举。
- 48.旋转图像
    - 把旋转变成一次对角线轴对称+一次横轴对称。
- 49.字母异位词分组
    - 哈希表。
    - 注意自定义哈希函数的写法。
- 50.Pow(x, n)
    - 快速幂。
- 51.N皇后
    - DFS搜索。
    - 注意在同一个对角线的旗子的行和列的和或差有相等关系。
    - 预处理把每一种摆放的情况求出来。
- 52.N皇后 II
    - DFS搜索。
    - 注意在同一个对角线的旗子的行和列的和或差有相等关系。
- 53.最大子数组和
    - DP。
    - `dp[i]`表示以i结尾的最大子数组和。
- 54.螺旋矩阵
    - 模拟。
    - 每一轮之后更新`up`, `down`, `left`, `right`。
- 55.跳跃游戏
    - 贪心。
    - 每次从当前能选择的集合中尝试跳到最远的位置。
- 56.合并区间
    - 模拟。
    - 先把区间从小到大排序。然后尝试合并。
- 57.插入区间
    - 模拟。
    - 维护新插入区间的左右位置。
- 58.最后一个单词的长度
    - 从后向前遍历。
- 59.螺旋矩阵 II
    - 模拟。
    - 每一轮之后更新`up`, `down`, `left`, `right`。
- 60.排序序列 x
    - DFS。
    - 预先求出每个长度的排列个数。然后用DFS枚举：排列的每一位要是几才能满足最后是第k个排列。
- 61.旋转链表
    - 链表模拟。注意要把新的尾结点的next设置为NULL。
- 62.不同路径
    - DP。`dp[i][j]`是到这个位置的路径数量。
- 63.不同路径 II
    - DP。`dp[i][j]`是到这个位置的路径数量。
    - 注意要初始化第一行和第一列时候要注意有没有障碍。
- 64.最小路径和
    - DP。`dp[i][j]`是到这个位置的最小路径和。
- 65.有效数字
    - 应该用状态机转换来做。但是我的做法完全就是根据测试用例打补丁。
- 66.加一
    - 模拟。
- 67.二进制求和
    - 模拟。类似于第2题。
- 68.文本左右对齐 x
    - 复杂的模拟。
- 69.x的平方根
    - 二分答案。
    - 注意用`int64_t`。
- 70.爬楼梯
    - 递推。
- 71.简化路径
    - 用栈模拟。用状态机来处理字符串。
- 72.编辑距离
    - DP。`dp[i][j]`是`word1[0...i-1]`转换成`word2[0...j-1]`的最少操作数。
- 73.矩阵置零。
    - 模拟。
- 74.搜索二维矩阵
    - 两次二分查找。或者把整体看成一个大数组，做一次二分查找。
- 75.颜色分类
    - 扫两遍。第一遍排序0，第二遍排序1。
- 76.最小覆盖子串
    - 滑动窗口。
    - 每次右移左指针1位，之后把右指针往右移动到正好覆盖的位置。
- 77.组合
    - DFS枚举。
- 78.子集
    - DFS枚举。
- 79.单词搜索
    - DFS。
- 80.删除有序数组中的重复项 II
    - 双指针维护字母相同的窗口。
    - 再用一个idx维护删除后的元素位置。
- 81.搜索旋转排序数组 II
    - 二分查找。
    - 要分成两段递增段。注意target的可能位置。注意取等的情况。
- 82.删除排序链表中的重复元素 II
    - 链表模拟。
- 83.删除排序链表中的重复元素
    - 链表模拟。
- 84.柱状图中最大的矩形
    - 单调栈。
    - 维护一个单调递增的栈。从左往右遍历一遍，再从右往左遍历一遍。本质上是找到元素i左边（右边）第一个比它矮的元素。
- 85.最大矩形 x
    - 单调栈。
    - 先算`left[i][j]`是元素`(i, j)`及其左边连续的1的个数。然后上下的层次上，应用第84题的单调栈方法。

- 121.买卖股票的最佳时机
    - 只能买卖一次。只需要维护前i天价格的最小值，然后看第i天卖的时候挣多少钱。
- 122.买卖股票的最佳时机 II
    - DP。
    - `dp[i][0]`是在第i天，不持有股票状态的最大利润；`dp[i][1]`是在第i天，持有股票状态的最大利润。
    - `dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);`
    - `dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);`
- 134.加油站 x
    - 贪心。
    - 相当于把`(gas[i] - cost[i])`当成一条折线，需要找到折线中最低的点。它的下一个点就是起始位置。如果总和小于0，肯定是过不去的。
- 135.分发糖果 x
    - 贪心。
    - 先从左往右遍历，处理当前节点比它的左边节点高的情况。然后从右往左遍历，处理当前节点比它的右边节点高的情况。
- 151.反转字符串中的单词
    - 从后往前遍历字符串。用双指针摘出来每个单词再reverse。
- 169.多数元素
    - Boyer-Moore 投票算法。
    - 如果我们把众数记为 +1，把其他数记为 −1，将它们全部加起来，显然和大于 0。
        - 算法的思想是如果当前元素等于candidate,就增加count。
        - 否则就减小count，如果小于0就把candidate改为当前元素，并且count置为1。
- 189.轮转数组 x
    - 想法是：轮转后，第i个位置应该填第i-k位置，第i-k位置应该填i-2k位置，依次类推最后会形成一个环。
    - 环的个数是n和k的最大公约数。

- 215.数组中的第K个最大元素 x
    - 分治法。
    - 注意分治时候两边都不能出现>=和<=，都用>和<。有全是1的样例卡常数。
- 235.二叉搜索树的最近公共祖先
    - 用二叉搜索树中值的性质来划分。
- 236.二叉树的最近公共祖先 x
    - 就用本身的函数递归做。祖先一定满足他的左右儿子遍历完返回的值都不是nullptr。
- 238.除自身以外数组的乘积
    - 维护一个前缀积+后缀积。
    - 前缀积的i从1开始取。表示“前i个元素的乘积”。

- 274.H 指数
    - 从小到大排序。然后倒序遍历一下判断H指数。
- 380.O(1) 时间插入、删除和获取随机元素
    - 用一个`vector`保存元素，用一个`map<int, int>`维护元素值->vector中元素的索引。
    - 当删除一个元素时，先把该元素和数组尾部的元素交换再删除。
- 
- 1738.找出第 K 大的异或坐标值
    - 异或前缀和。
    - 使用`nth_element`。
