#include <vector>
using namespace std;
// 用一个前缀数组和一个后缀数组
// O(1)空间的类似，一边计算前缀和后缀时，一边更新答案
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        vector<int> suffix(n + 1);
        prefix[0] = 1;
        suffix[n] = 1;
        for(int i = 0; i < n; ++i){
            prefix[i + 1] = prefix[i] * nums[i];
        }
        for(int i = n; i >= 1; --i){
            suffix[i - 1] = suffix[i] * nums[i - 1];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            ans[i] = prefix[i] * suffix[i + 1]; 
        }
        return ans;
    }

};