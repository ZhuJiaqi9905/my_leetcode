//把原数组当成哈希表，每次加n。
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto & num : nums){
            int x = (num - 1)% n;//这里要先减一在取模
            nums[x] += n;
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(nums[i] <= n){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};