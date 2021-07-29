class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        for(; i < k; ++i){
            ans += nums[i];
        }
        int tmp = ans;
        for(; i < n; ++i){
            tmp = tmp + nums[i] - nums[i - k];
            ans = std::max(tmp, ans);
        }
        return double(ans) / k;
    }
};