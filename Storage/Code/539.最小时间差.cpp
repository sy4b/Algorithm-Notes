/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
/*
    将时间转换成分钟数，需要额外记录最小时间加上24*60的时间
    所有时间保存在数组中，挨个更新min
    ---
    SET记录时间，碰到已经存在的直接返回0
*/
class Solution {
    int helper(string& h){
        int hour=0, min=0;
        hour+=h[0]-'0';
        hour=hour*10+h[1]-'0';
        min=hour*60+(h[3]-'0')*10+h[4];
        return min;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        set<int> st;
        for(auto& s: timePoints){
            int temp=helper(s);
            time.push_back(temp);
            if(st.count(temp))  return 0;
            st.insert(temp);
        }
        sort(time.begin(), time.end());
        // 将最小的时间加上24*60添加到末尾
        time.push_back(time[0]+24*60);
        int ans=INT_MAX;
        for(int i=0;i<time.size()-1;++i){
            ans=min(ans, time[i+1]-time[i]);
        }
        return ans;
    }
};
// @lc code=end

