class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        //空格
        for(; i < n; ++i){
            if(s[i] != ' '){
                break;
            }
        }
        //符号
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            ++i;
        }else if(s[i] == '+'){
            ++i;
        }
        int64_t ans = 0;
        //前导0
        for(; i < n; ++i){
            if(s[i] != '0'){
                break;
            }
        }
        //解析数字
        for(; i < n; ++i){
            if(s[i] < '0' || s[i] > '9'){
                break;
            }
            ans *= 10;
            ans += (s[i] - '0');
            if(sign > 0 && ans > ((1L << 31) - 1)){
                return ((1L << 31) - 1);
            }
            if(sign < 0 && ans > ((1L << 31))){
                return -(1L << 31);
            }
        }
        ans *= sign;
        return ans;
    }
};