class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int s = 0; 
        int e = 0;
        int zeros = 0;
        int ans = 0;
        while(e < n){
            while(e < n && zeros <= K){
                if(A[e] == 0){
                    zeros++;
                }
                e++;
            }
            if(e == n && zeros <= K){//特判右指针出界的情况
                ans = std::max(ans, e - s);
            }else{
                ans = std::max(ans, e - s - 1);
            }
           
            while(zeros > K){
                if(A[s] == 0){
                    zeros--;
                }
                s++;
            }
        }
        return ans;
    }
};