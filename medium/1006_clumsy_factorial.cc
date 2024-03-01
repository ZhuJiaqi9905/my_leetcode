class Solution {
public:
    int clumsy(int n) {
        bool flag = false;
        int ans = 0;
        int k = n / 4;
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        if(n == 3) {
            return 6;
        }
        
        while(k--) {

            if(!flag) {
                ans = n * (n - 1) / (n - 2) + (n - 3);
                flag = true;
            }else{
                ans = ans - n * (n - 1) / (n - 2) + (n - 3);
            }
            n -= 4;
        }
        switch (n % 4) {
            case 0:
                break;
            case 1:
                ans -= 1;
                break;
            case 2:
                ans -= 2;
                break;
            case 3:
                ans -= 6;
                break;
        }
        return ans;
    }
};
int main() {}