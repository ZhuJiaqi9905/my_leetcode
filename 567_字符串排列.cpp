// 不要被排列骗了。如果s1的排列是s2的子串，只需要找到s2中长度为m的子串，使得子串的每个字符频率与s1相同
// 本质是一个滑动窗口
// 注意边界条件
// 还可以维护一个两字符串频率不同的字符个数，这样就不需要每次调用equal_frequency()进行调用
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> s1_set(26);
        int m = s1.size();
        int n = s2.size();
        if(m > n){
            return false;
        }
        for(auto&ch : s1){
            ++s1_set[ch - 'a'];
        }
        vector<int> s2_set(26);
        int s = 0; int e = 0;
        for(; e < m; ++e){
            ++s2_set[s2[e] - 'a'];
        }
        --e;//注意这里把右窗口减1，保证是闭区间
        if(equal_frequency(s1_set, s2_set)){
            return true;
        }
        //找到s2中长度为m的子串，使得子串的每个字符频率与s1相同
        while(e < n - 1){//注意边界是n-1
            --s2_set[s2[s] - 'a'];
            ++s;
            ++e;
            ++s2_set[s2[e] - 'a'];
            if(equal_frequency(s1_set, s2_set)){
                return true;
            }
        }
        return false;
    }
    bool equal_frequency(vector<int>& v1, vector<int>& v2){
        for(int i = 0; i < 26; ++i){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
};