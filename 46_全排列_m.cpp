#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> visit;
    vector<vector<int>> ans;
    int n; 
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visit.resize(n);
        vector<int> tmp_ans;
        dfs(nums, 0, tmp_ans);
        return ans;
    }
    //k是要填第k个位置
    void dfs(vector<int>& nums, int k, vector<int>& tmp_ans){
        if(k == n){
            //如果已经都排过了
            ans.push_back(tmp_ans);
            return;
        }
        for(int i = 0; i < n; ++i){//遍历所有可能填入的值
            if(!visit[i]){
                tmp_ans.push_back(nums[i]);
                visit[i] = true;
                dfs(nums, k + 1, tmp_ans);
                visit[i] = false;
                tmp_ans.pop_back();
            }
        }
    }
};