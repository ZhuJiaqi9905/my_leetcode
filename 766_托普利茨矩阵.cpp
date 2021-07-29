class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      //只需要把每个元素和它最上方的元素相比即可
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(matrix[i][j] != matrix[i - 1][j - 1]){
                    return false;
                }
            }
        }
        return true;
        //方法二是每一个对角线相比
        // int k = n + m - 1;
        // for(int i = 0; i < n; ++i){
        //     int tmp = matrix[i][0];
        //     for(int j = i + 1; j < n; ++j){
        //         if((j - i < m) && matrix[j][j - i] != tmp){
        //             return false;
        //         }
        //     }
        // }
        // for(int i = 1; i < m; ++i){
        //     int tmp = matrix[0][i];
        //     for(int j = i + 1; j < m; ++j){
        //         if((j - i < n) && matrix[j - i][j] != tmp){
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
};