// 或者同时统计递增或递减。如果既递增又递减说明有问题
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n < 2) return true;
        int delta = 0;
        int i = 0;
        for(; i < n - 1; ++i){
            delta = A[i + 1] - A[i];
            if(delta != 0){
                break;
            }
        }
        for(; i < n - 1; ++i){
            if(delta * (A[i + 1] - A[i]) < 0){
                return false;
            }
        }
        return true;
    }
};