class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int** dp = new int*[n];
        for(int i = 0; i < n; ++i){
            dp[i] = new int[n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
            if(i < n - 1 && s[i] == s[i + 1]){
                dp[i][i + 1] = 2;
            }
        }
        for(int k = 3; k <= n; ++k){
            //k是子串长度
            for(int i = 0; (i+k-1) < n; ++i){
                int j = i + k - 1;
                if(s[i] == s[j] && (dp[i+1][j-1] != 0 || k == 3)){
                    
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
        }
        //得到答案
        int maxL = 0; int maxi = 0; int maxj = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(dp[i][j] > maxL){
                    maxL = dp[i][j]; maxi = i; maxj = j;
                }
            }
        }
        return s.substr(maxi, maxj - maxi + 1);
    }
};