// 双指针，滑动窗口
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return 1;
        int s = 0;
        int e = 1;
        while(e < n - 1 && arr[s] == arr[e]){//越过相邻元素相同的情况
            ++s; ++e;
        }
        if(e == n - 1 && arr[s] == arr[e]){//如果所有元素都相同
            return 1;
        }
        int ans = 2;
        while(e < n - 1){
            if((arr[e] > arr[e - 1] && arr[e] > arr[e + 1]) ||
                (arr[e] < arr[e - 1] && arr[e] < arr[e + 1])){
                    ++e;
                    ans = std::max(ans, e - s + 1);
            }else{
                s = e;
                ++e;
                while(e < (n - 1) && arr[s] == arr[e]){//越过相邻元素相同的情况
                    ++s; ++e;
                }
            }
        }
        return ans;
    }
};