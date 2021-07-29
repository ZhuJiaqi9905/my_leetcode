class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> diff(n + 1);//diff[i]是A[i]的反转次数与A[i-1]的反转次数的差
        int ans = 0; 
        int rev_cnt = 0;//记录目前为止元素i的反转次数
        for(int i = 0; i < n; ++i){
            rev_cnt += diff[i];
            if(((A[i] + rev_cnt) & 1) == 0){
                if(i + K > n){
                    return -1;
                }
                ++diff[i];
                ++ans;
                ++rev_cnt;
                --diff[i + K];
            }
            
        }
        return ans;
    }
    
};
//因为A[i]只有0和1两个值，所以用A[i] += 2表示它被翻转，从而优化了diff数组的空间。
class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i - K] > 1) {
                revCnt ^= 1;
                A[i - K] -= 2; // 复原数组元素，若允许修改数组 A，则可以省略
            }
            if (A[i] == revCnt) {
                if (i + K > n) {
                    return -1;
                }
                ++ans;
                revCnt ^= 1;
                A[i] += 2;
            }
        }
        return ans;
    }
};
