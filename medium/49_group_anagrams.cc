#include <algorithm>
#include <array>
#include <cstddef>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/// 用计数+哈希表。注意学习如何给自定义的类实现哈希函数。
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    // 注意如何写哈希函数
    auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
        return (acc << 1) ^ fn(num);
      });
    };
    // 注意这里的变量定义
    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> dict(
        0, arrayHash);

    for (const auto &str : strs) {
      int len = str.length();
      array<int, 26> arr{};
      for (int i = 0; i < len; ++i) {
        arr[str[i] - 'a']++;
      }
      if (dict.find(arr) == dict.end()) {
        dict.emplace(std::move(arr), vector<string>{str});
      } else {
        dict[arr].emplace_back(str);
      }
    }
    vector<vector<string>> ans;
    for (auto &kv : dict) {
      ans.emplace_back(std::move(kv.second));
    }
    // std::transform(dict.begin(), dict.end(), std::back_inserter(ans),
    //                [](const auto &pair) { return pair.second; });
    return ans;
  }
};