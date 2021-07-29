//二维前缀和 sum[i][j] 是从(0, 0)到(i - 1, j - 1)的矩形区域的和
class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        sums.resize(m + 1, vector<int>(n + 1));
        sums[0][0] = 0;
        for(int i = 1; i <= n; ++i){
            sums[0][i] = sums[0][i - 1] + matrix[0][i - 1];
        }
        for(int i = 1; i <= m; ++i){
            sums[i][0] = sums[i - 1][0] + matrix[i - 1][0];
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] + sums[row1][col1] - sums[row2 + 1][col1] - sums[row1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */