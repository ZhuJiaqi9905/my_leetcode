#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  const int L = 10;
  unordered_map<char, int> bin = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};
  vector<string> findRepeatedDnaSequences(string s) {
    int n = s.length();
    unordered_map<string, int> map;
    vector<string> ans;
    for (int i = 0; i <= n - L; ++i) {
      string word = s.substr(i, L);
      if (++map[word] == 2) {
        ans.push_back(std::move(word));
      }
    }
    return ans;
  }

  /// 方法二：用二进制表示ATCG来编码字符串。利用滑动窗口快速计算编码。
  vector<string> findRepeatedDnaSequences2(string s) {
    int n = s.length();
    vector<string> ans;
    if (n <= L) {
      return ans;
    }
    int x = 0;
    for (int i = 0; i < L - 1; ++i) {
      x = (x << 2) | bin[s[i]];
    }
    unordered_map<int, int> map;
    // map[x] = 1;
    for (int i = 0; i <= n - L; ++i) {
      x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
      if (++map[x] == 2) {
        ans.push_back(s.substr(i, L));
      }
    }
    return ans;
  }
};

int main() {
  Solution s1;
  s1.findRepeatedDnaSequences2("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
}