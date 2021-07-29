// 分治法。找出每个子串中数目小于K的字符，作为子串的分隔符，进行分治
class Solution {
public:
    int dfs(string& s, int begin, int end, int k){
        std::map<char, int> ch_cnt;
        for(int i = begin; i <= end; ++i){
            ++ch_cnt[s[i]];
        }
        int flag = false;
        std::set<char> split_ch;
        for(auto& ele: ch_cnt){
            if(ele.second < k){
                split_ch.insert(ele.first);//分隔字符
            }
        }
        if(split_ch.size() == 0){//都满足大于等于k
            return end - begin + 1;
        }
        int ans = 0;
        int b = begin;
        for(int i = begin; i <= end; ++i){
            if(split_ch.find(s[i]) != split_ch.end()){
                if(b < i){
                    ans = std::max(dfs(s, b, i - 1, k), ans);
                }
                b = i + 1;
            }
        }
        ans = std::max(dfs(s, b, end, k), ans);
        return ans;

    }

    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }  
};
// 滑动窗口。枚举滑动窗口允许出现的字符种类数t。
// 如果当前窗口的字符种类数tot大于t，就把左端点右移。
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        int n = s.length();
        for (int t = 1; t <= 26; t++) {//枚举允许出现的字符种类数
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int tot = 0;//维护字符种类数
            int less = 0;//维护小于K的字符种类数
            while (r < n) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;
                }

                while (tot > t) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
};
