/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
/*
    从左向右扫描
    1. 遇到数字，就入栈
    2. 遇到算术符号，出栈两个元素进行计算，结果入栈
    3. 最后栈顶就是答案
*/

// @lc code=start
class Solution {
    int helper(string& s){
        int ans=0, sign=1;
        for(int i=0;i<s.size();++i){
            if(s[i]=='-'){
                sign=-1;
                continue;
            }
            ans=ans*10+s[i]-'0';
        }
        return sign*ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto& t: tokens){
            if(t=="+"){
                int n1=stk.top();
                stk.pop();
                int n2=stk.top();
                stk.pop();
                stk.push(n2+n1);
            }else if(t=="-"){
                int n1=stk.top();
                stk.pop();
                int n2=stk.top();
                stk.pop();
                stk.push(n2-n1);
            }else if(t=="*"){
                int n1=stk.top();
                stk.pop();
                int n2=stk.top();
                stk.pop();
                stk.push(n1*n2);
            }else if(t=="/"){
                int n1=stk.top();
                stk.pop();
                int n2=stk.top();
                stk.pop();
                stk.push(n2/n1);
            }else{
                stk.push(helper(t));
            }
        }
        return stk.top();
    }
};
// @lc code=end

