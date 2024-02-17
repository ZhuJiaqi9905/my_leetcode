#include<bits/stdc++.h>
#include<gtest/gtest.h>

using namespace std;
/// 多源BFS。从每个陆地同时开始BFS
class Solution {
public:
    struct Node{
        int x;
        int y;
    };
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        deque<Node> d;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) { // 如果是陆地
                    d.emplace_back(Node{i, j});
                    mp[i * n + j] = 0;
                }
            }
        }
        int ans = -1;

        while(!d.empty()) {
            Node nd = d.front();
            d.pop_front();
            int dx = nd.x;
            int dy = nd.y;
            int step = mp[dx * n + dy];
            for(int i = 0; i < 4; ++i) {
                int nx = dx + dirs[i][0];
                int ny = dy + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                // 如果一个「海洋」区域被访问到，说明其被离它「最近的陆地」覆盖到了，修改值为最小距离。这样我们只需要考虑那些值仍然为 000 的「海洋」区域即可
                if (grid[nx][ny] != 0) continue;
                grid[nx][ny] = step + 1;
                d.emplace_back(Node{nx, ny});
                mp[nx * n + ny] = step + 1;
                ans = max(ans, step + 1);
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> g1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    Solution s1;
    EXPECT_EQ(s1.maxDistance(g1), 2);

}