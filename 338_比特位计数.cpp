// 动态规划，维护最高位
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        int highbit = 0;
        for(int i = 1; i <= num; ++i){
            if((i & ( i - 1)) == 0){
                //如果i是2的整数次幂
                highbit = i;
            }
            bits[i] = bits[i - highbit] + 1;
        }return bits;

    }
    
};