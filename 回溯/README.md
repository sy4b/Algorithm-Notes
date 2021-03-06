# 回溯

回溯是一种暴力搜索算法，本质上是dfs

回溯适合用来求解排列、组合、子集、分割、棋盘问题

回溯的问题一般都可以抽象为树形结构。我们搜索的过程是在递归树上进行，在搜索的过程中收集答案，返回上一个状态（回溯）的时候需要恢复原始状态。同时，应当考虑如何对树枝进行修剪，去除重复状态或无效状态，降低搜索耗时

回溯函数的模板

```cpp
void backTrack(/*params*/){
  if(/*递归终止条件*/){
    ... // 收集答案
    return;
  }
  ...                     // 状态推进、记录
  backTrack(/*params*/);  // 进入递归
  ...                     // 恢复状态
}
```

---

# 组合问题

## Leetcode 77. 组合

[Leetcode 题目链接](https://leetcode-cn.com/problems/combinations/)

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

```cpp
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

我们可以把搜索过程抽象出来：
