/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start

// struct node{
//     int x;
//     int y;
//     node(int xx, int yy):x(xx), y(yy){}
// };
// bool operator<(const node& A, const node& B){
//     return A.x*B.y>B.x*A.y;
// }
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         priority_queue<node, vector<node>>pq;
//         for(int i=0;i<arr.size()-1;++i){
//             for(int j=i+1;j<arr.size();++j){
//                 pq.push(node(arr[i], arr[j]));
//             }
//         }
//         for(int i=1;i<k;++i){
//             pq.pop();
//         }
//         return vector{pq.top().x, pq.top().y};
//     }
// };

// 手写堆
class Solution {
    // pair比较
    bool helper(pair<int, int>& p1, pair<int, int>& p2){
        int n1=p1.first*p2.second;
        int n2=p2.first*p1.second;
        return n1<n2;
    }
    // 存储堆的数组
    vector<pair<int, int>> vec;
    // 记录堆的大小
    int len=0;
    // 新元素插入堆
    void insert(vector<pair<int, int>>& vec, pair<int, int>& p, int& len){
        if(len==vec.size()){
            vec.push_back(p);
        }else{
            vec[len]=p;
        }
        ++len;
        // 排序
        int index=len-1;        // 追踪插入的元素
        while((index-1)/2>=0 && helper(vec[index], vec[(index-1)/2])){
            swap(vec[index], vec[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    // 移出堆顶元素
    void del(vector<pair<int,int>>& vec, int& len){
        // 交换堆头和尾，缩小堆，再堆化
        swap(vec[0], vec[len-1]);
        --len;
        int index=0;            // 追踪需要重新排序的元素
        while(index*2+1<len || index*2+2<len){
            if(index*2+2<len){
                if(helper(vec[index], vec[index*2+1]) && helper(vec[index], vec[index*2+2])){
                    break;
                }else{
                    if(helper(vec[index*2+1], vec[index*2+2])){
                        swap(vec[index], vec[index*2+1]);
                        index=index*2+1;
                    }else{
                        swap(vec[index], vec[index*2+2]);
                        index=index*2+2;
                    }
                }
            }else{
                if(helper(vec[index], vec[index*2+1])){
                    break;
                }else{
                    swap(vec[index], vec[index*2+1]);
                    index=index*2+1;
                }
            }
        }
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        for(int i=0;i<arr.size()-1;++i){
            for(int j=i+1;j<arr.size();++j){
                auto p=make_pair(arr[i], arr[j]);
                insert(vec, p, len);
            }
        }
        for(int i=1;i<k;++i){
            del(vec, len);
        }
        return vector<int>{vec[0].first, vec[0].second};
    }
};
// @lc code=end

