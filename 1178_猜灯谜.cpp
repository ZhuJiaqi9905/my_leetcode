// 因为字母只有26中情况，所以用一个uint_32t表示一个单词所包含的字母。
// 每个单词对应的字母集合是word_set
// words_cnt记录word_set中每个元素的个数
// 对于每个puzzle，枚举它的所有子集，如果其某个子集与words_set中的某个元素相等，说明是一个解
// 枚举子集时候，可以先把首字母置为0，然后再把首字母加上，保证子集都包含首字母
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = puzzles.size();
        int m = words.size();
        vector<uint32_t> words_set(m);
        for(int i = 0; i < m; ++i){
            for(auto& ch: words[i]){
                words_set[i] |= (1 << (ch - 'a'));
            }
        }
        map<uint32_t, int> words_cnt;
        for(auto& ele: words_set){
            if (__builtin_popcount(ele) > 7) {
                continue;
            }

            if(words_cnt.find(ele) == words_cnt.end()){
                words_cnt[ele] = 1;
            }else{
                ++words_cnt[ele];
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            int mask = 0;
            for(int j = 1; j < 7; ++j){//先把首字母置为0
                mask |= (1 << (puzzles[i][j] - 'a'));
            }
            //枚举mask的子集,同时把首字母填上
            uint32_t subset = mask;
            do{
                int s = subset | (1 << (puzzles[i][0] - 'a'));//把首字母填上
                if(words_cnt.count(s)){
                    cnt += words_cnt[s];
                }
                subset = (subset - 1) & mask;
            }while(subset != mask);
            ans[i] = cnt;
        }
        return ans;
    }
};