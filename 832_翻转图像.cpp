class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> ans(A);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m/2; ++j){
                swap(ans[i][j], ans[i][m - j - 1]);
                ans[i][j] = !ans[i][j];
                ans[i][m - j - 1] = !ans[i][m - j - 1];
            }
            if((m & 1) == 1){
                ans[i][m / 2] = !ans[i][m / 2];
            }
        }
        return ans;
    }
};