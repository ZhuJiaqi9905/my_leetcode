#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans_;
    vector<int> tmp_ans_;
    int n_;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n_ = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans_;
    }

    void dfs(vector<int>& candidates, int target, int idx) {
        if(target == 0){
            ans_.push_back(tmp_ans_);
        }
        for(int i = idx; i < n_; ++i) {
            if(target < candidates[i]) {
                break;
            }
            tmp_ans_.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            tmp_ans_.pop_back();
        }
    }
};
int main(){}