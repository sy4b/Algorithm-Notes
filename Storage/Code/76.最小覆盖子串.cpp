/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
/*
    滑动窗口：
    1. 什么时候移动右边界：当前窗口内的字符串，没有覆盖到子串
       右边界越出数组边界，程序可以退出
    2. 什么时候移动左边界：当前窗口的字符串已经覆盖到子串，需要把窗口尽可能缩小
       当继续缩小后不满足题意的时刻，就是满足的一个答案
    3. 多个答案需要比较字符串长度
    4. 因此需要使用unordered_map记录字符个数
    5. helper辅助函数，用来比较窗口内是否完全覆盖子串，当窗口某个字符频次小于子串对应字符，false
*/
class Solution {
    // 比较窗口和子串
    bool helper(unordered_map<char, int>& smap, unordered_map<char, int>& tmap){
        for(auto& c: tmap){
            if(smap[c.first]<c.second){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        string ans("");
        // 特殊判断：子串长度大于主串，直接""
        int slen=s.size(), tlen=t.size();
        if(tlen>slen)   return ans;
        // 变量定义
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        // 记录子串的字符个数
        for(auto& c: t){
            ++tmap[c];
        }
        // 滑动窗口
        int left=0, right=0;
        while(right<slen){
            ++smap[s[right]];
            // 尝试移动左边界
            while(helper(smap, tmap)){
                --smap[s[left]];
                ++left;
                if(helper(smap, tmap)){ // 可以移动
                    continue;
                }else{                  // 不可以移动
                    // 此时退无可退，是答案之一啦
                    // 答案区间[left-1, right]
                    if(ans==""){        // 还没有答案，直接加入
                        for(int i=left-1;i<=right;++i){
                            ans+=s[i];
                        }
                    }else{              // 取长度更小的作为答案
                        if(ans.size()>right-(left-1)+1){
                            ans="";
                            for(int i=left-1;i<=right;++i){
                                ans+=s[i];
                            }
                        }
                    }
                }
            }
            ++right;
        }
        return ans;
    }
};
// @lc code=end

