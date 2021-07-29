#include <queue>
/**
 * 建图，每一对情侣是一个点，如果两对不同的情侣中的两个人坐到一起，就给他们所属的两个点连一条无向边。
 * 对图进行bfs求出每个连通分量中的点个数。对于一个含有n个点的连通分量，需要交换n-1次
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int num = n / 2;
        vector<vector<int>> graph(num);
        for(int i = 0; i < n; i += 2){
            int u = row[i] / 2;
            int v = row[i + 1] / 2;
            if(u != v){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        vector<bool> visit(num, false);
        int ans = 0;
        for(int i = 0; i < num; ++i){
            if(!visit[i]){
                visit[i] = true;
                ans +=bfs(i, graph, visit) - 1;
            }
        }
        return ans;
    }
    int bfs(int start, vector<vector<int>> &graph, vector<bool>& visit){
        std::queue<int> que;
        que.push(start);
        int num = 1;
        while(!que.empty()){
          int u = que.front();
          que.pop();
          for(auto& v: graph[u]){
            if(!visit[v]){
              visit[v] = 1;
              que.push(v);
              num++;
            }
          }
        }
        return num;
    }
};
/**
 * 使用并查集求联通分量
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int num = n / 2;
        //初始化并查集
        vector<int> parent(num);
        vector<int> sums(num);
        for(int i = 0; i < num; ++i){
            parent[i] = i;
            sums[i] = 1;
        }
        for(int i = 0; i < n; i += 2){
            int u = row[i] / 2;
            int v = row[i + 1] / 2;
            add(parent, u, v, sums);
        }
        int ans = 0;
        for(int i = 0; i < num; ++i){
            if(parent[i] == i){
                ans += sums[i] - 1;
            }
        }
        return ans;
    }
    int getRoot(vector<int>& parent, int u){
        if(parent[u] == u){
            return u;
        }
        //路径压缩
        int new_par = getRoot(parent, parent[u]);
        parent[u] = new_par;
        return new_par;
    }
    void add(vector<int>& parent, int x, int y, vector<int>& sums){
        int px = getRoot(parent, x);
        int py = getRoot(parent, y);
        if(px == py){
            return;
        }
        parent[py] = px;
        sums[px] += sums[py];
    }
};