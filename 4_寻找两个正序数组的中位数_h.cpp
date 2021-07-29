class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        if(((m + n) & 1) == 0){
            //偶数
           
           return (getKth(nums1, 0, nums2, 0, (m+n+1)/2) + getKth(nums1, 0, nums2, 0, (m+n+2)/2))/2.0;
        }else{
            return getKth(nums1, 0, nums2, 0, (m+n+1)/2);
        }
    }
    //找到两个有序数组中第k大元素。k从1开始取
    int getKth(vector<int>& v1, int s1, vector<int>& v2, int s2, int k){
        int len1 = v1.size();
        int len2 = v2.size();
        if(s1 >= len1){
            return v2[s2 + k - 1];
        }
        if(s2 >= len2){
            return v1[s1 + k - 1];
        }
        if(k == 1){
            return min(v1[s1], v2[s2]);
        }
        
        //分别查找两个数组的第k/2个元素
        int num1Mid; int num2Mid;
        
           
        num1Mid = s1 + k/2 - 1 < len1 ? v1[s1 + k/2 - 1]: INT_MAX;
        num2Mid = s2 + k/2 - 1 < len2 ? v2[s2 + k/2 - 1]: INT_MAX;
        
        
        if(num1Mid < num2Mid){
            return getKth(v1, s1 + k/2, v2, s2, k - k/2);
        }else{
            return getKth(v1, s1, v2, s2 + k/2, k - k/2);
        }
    }

};