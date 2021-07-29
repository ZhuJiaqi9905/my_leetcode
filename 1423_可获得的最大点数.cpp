// 本质是维护最左+最右的k个数的和的滑动窗口。
// 这里事先把它们都求出来了，实际上不求也行
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> left(k + 1);
        vector<int> right(k + 1);

        left[0] = 0;
        for(int i = 0; i < k; ++i){
            left[i + 1] = left[i] + cardPoints[i];
        }
        right[0] = 0;
        for(int i = 0; i < k; ++i){
            right[i + 1] = right[i] + cardPoints[n - i - 1];
        }
        int ans = 0;
        for(int i = 0; i <= k; ++i){
            ans = std::max(ans, left[i] + right[k - i]);
        }
        return ans;
    }
};