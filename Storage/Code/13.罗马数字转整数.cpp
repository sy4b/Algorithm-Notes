/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int len=s.size();
        for(int index=0;index<len;++index){
            if(s[index]=='I'){
                ans+=1;
            }
            if(s[index]=='V'){
                if(index>0 && s[index-1]=='I'){
                    ans+=3;
                }else{
                    ans+=5;
                }
            }
            if(s[index]=='X'){
                if(index>0 && s[index-1]=='I'){
                    ans+=8;
                }else{
                    ans+=10;
                }
            }
            if(s[index]=='L'){
                if(index>0 && s[index-1]=='X'){
                    ans+=30;
                }else{
                    ans+=50;
                }
            }
            if(s[index]=='C'){
                if(index>0 && s[index-1]=='X'){
                    ans+=80;
                }else{
                    ans+=100;
                }
            }
            if(s[index]=='D'){
                if(index>0 && s[index-1]=='C'){
                    ans+=300;
                }else{
                    ans+=500;
                }
            }
            if(s[index]=='M'){
                if(index>0 && s[index-1]=='C'){
                    ans+=800;
                }else{
                    ans+=1000;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

