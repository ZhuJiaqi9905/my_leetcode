// 注意枚举子集的写法
// 用dfs也能做
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int mask = (1 << n) - 1;
        int subset = mask;
        do{
            vector<int> tmp_ans;
            for(int i = 0; i < n; ++i){
                if((subset & (1 << i)) != 0){
                    tmp_ans.push_back(nums[i]);
                }
            }
            ans.push_back(tmp_ans);
            //枚举子集
            subset = (subset - 1) & mask;
        }while(subset != mask);
        return ans;
    }
};