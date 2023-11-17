#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution {
public:
  /// n个' '组成的字符串
  string blank(int n) { return string(n, ' '); }

  /// 从words[left]拼接到words[right - 1]。每个word之间用一个sep分割
  string join(vector<string> &words, int left, int right, string sep) {
    string s = words[left];
    for (int i = left + 1; i < right; ++i) {
      s += sep + words[i];
    }
    return s;
  }

  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ans;
    int right = 0;
    int n = words.size();
    while (true) {
      int left = right;
      int sum_len = 0;
      while (right < n &&
             sum_len + words[right].length() + right - left <= maxWidth) {
        sum_len += words[right].length();
        right++;
      }

      // 如果是最后一行
      if (right == n) {
        string s = join(words, left, n, " ");
        ans.emplace_back(s + blank(maxWidth - s.length()));
        return ans;
      }

      int num_words = right - left;
      int num_space = maxWidth - sum_len;

      // 当前行只填了一个单词，该单词左对齐
      if (num_words == 1) {
        ans.emplace_back(words[left] + blank(num_space));
        continue;
      }
      // 当前行填了多个单词
      int avg_space = num_space / (num_words - 1);
      int extra_space = num_space % (num_words - 1);
      string s1 = join(words, left, left + extra_space + 1,
                       blank(avg_space + 1)); // 拼接额外加一个空格的单词
      string s2 = join(words, left + extra_space + 1, right,
                       blank(avg_space)); // 拼接其余单词
      ans.emplace_back(s1 + blank(avg_space) + s2);
    }
    return ans;
  }
};
int main() {
    Solution s;
}