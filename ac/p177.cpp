// 果冻收藏家
#include <bits/stdc++.h>
using namespace std;

int n;

unordered_set<int> st;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st.insert(x);
  }
  cout << n - st.size() << endl;
  return 0;
}