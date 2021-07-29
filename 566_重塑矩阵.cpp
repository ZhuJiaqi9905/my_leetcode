class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if(n * m != r * c){
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        int x = 0; int y = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans[x][y] = nums[i][j];
                y++;
                if(y >= c){
                    x++;
                    y = 0;
                } 
            }
        }
        return ans;
    }
};