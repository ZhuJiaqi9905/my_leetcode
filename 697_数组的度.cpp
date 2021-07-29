class Solution {
public:
    const int kLen = 50000;
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int cnt[kLen]; int max_val = 0;
        memset(cnt, 0, sizeof(cnt));
        for(auto& ele: nums){
            cnt[ele]++;
        }
        max_val = *std::max_element(cnt, cnt + kLen);//求出最大的度
        //滑动窗口
        int s = 0;
        int e = 0;
        int ans = kLen + 1;
        int *freq = new int[kLen]();//记录窗口中的每个数的频数
        while(e < n){
            freq[nums[e]]++;
            while(freq[nums[e]] == max_val){
                ans = std::min(ans, e - s + 1);//这里不要在while循环外更新，
                                              //否则需要有一个变量来告诉它是从这个while中跳出来的
                freq[nums[s]]--;
                s++;
            }
            e++;
            
        }
        delete []freq;
        return ans;
    }
    
};