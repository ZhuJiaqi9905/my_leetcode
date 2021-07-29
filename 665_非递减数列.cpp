// [-1, 4, 2, 3] true
// [3, 4, 2, 3] false
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        auto n = nums.size();
        int top = 0;
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] > nums[i + 1]){
                ++cnt;
                if(cnt > 1){
                    return false;
                }
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                }

            }
            
        }
        return true;
    }
};