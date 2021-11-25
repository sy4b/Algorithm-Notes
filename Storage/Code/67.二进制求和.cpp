/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int index1=a.size()-1;
        int index2=b.size()-1;
        int carry=0;
        string ans="";
        while(index1>=0 || index2>=0){
            int val1=index1>=0?a[index1]-'0':0;
            int val2=index2>=0?b[index2]-'0':0;
            int sum=val1+val2+carry;
            ans+=char('0'+sum%2);
            carry=sum/2;
            if(index1>=0)   --index1;
            if(index2>=0)   --index2;
        }
        if(carry!=0)    ans+='1';
        int len=ans.size();
        for(int i=0;i<len/2;++i){
            char temp=ans[i];
            ans[i]=ans[len-1-i];
            ans[len-1-i]=temp;
        }

        return ans;
    }
};
// @lc code=end

