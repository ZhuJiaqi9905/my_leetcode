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

- 37


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