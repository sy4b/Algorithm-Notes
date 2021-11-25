/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n&(n-1) 将最右边1变为0
        // n&(-n)  找到最右边的1
        int count=0;
        while(n){
            ++count;
            n=n&(n-1);
        }
        return count;
    }
};
// @lc code=end

