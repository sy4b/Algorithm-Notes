/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
    int newInt(int n){
        int ans=0;
        while(n>0){
            int temp=n%10;
            ans+=temp*temp;
            n=n/10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        // 数字不会越来愈大，可以证明
        // 那么只剩下循环 和 变为1 两种情况
        unordered_set<int> st;
        while(n>1){
            if(st.count(n)){
                return false;
            }
            st.insert(n);
            n=newInt(n);
        }
        return true;
    }
};
// @lc code=end

