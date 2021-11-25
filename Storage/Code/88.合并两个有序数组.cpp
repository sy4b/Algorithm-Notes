/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)    return;
        if(m==0){
            for(int i=0;i<n;++i){
                nums1[i]=nums2[i];
            }
            return;
        }    
        // index是插入的位置
        int index1=m-1, index2=n-1, index=nums1.size()-1;
        while(index1>=0 || index2>=0){
            if(index1<0){
                nums1[index]=nums2[index2];
                --index2;
            }else if(index2<0){
                nums1[index]=nums1[index1];
                --index1;
            }else if(nums1[index1]<nums2[index2]){
                nums1[index]=nums2[index2];
                --index2;
            }else{
                nums1[index]=nums1[index1];
                --index1;
            }
            --index;
        }
    }
};
// @lc code=end

