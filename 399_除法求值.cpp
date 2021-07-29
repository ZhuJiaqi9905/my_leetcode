// 建图，用bfs
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
private:
    vector<vector<pair<int, double> > > graph_;
    unordered_map<string, int> map_;
    int cnt_ = 0;


public:
    class Node{
        public:
            int s; double v;
    };
    double bfs(int begin, int end){
        set<int> visit;
        queue<Node> que;
        Node nd; nd.s = begin; nd.v = 1; visit.insert(begin);
        que.push(nd);
        while(!que.empty()){
            Node front = que.front(); que.pop();
            if(front.s == end){
                return front.v;
            }
            for(auto iter = graph_[front.s].begin(); iter != graph_[front.s].end(); ++iter){
                if(visit.find(iter->first) != visit.end()){
                    continue;
                }
                Node nnd; 
                nnd.s = iter->first;
                nnd.v = front.v * iter->second;
                visit.insert(nnd.s);
            }
        }
        return -1;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        graph_ = vector<vector<pair<int, double> > >(20);
        for(auto &s : equations){
            for(auto &ch : s){
                if(!map_.count(ch)) map_[ch] = cnt_++;
            }
        }

        for(int i = 0; i < n; ++i){
            int u = map_[equations[i][0]];
            int v = map_[equations[i][1]];
            graph_[u].push_back(make_pair(v, values[i]));
            graph_[v].push_back(make_pair(u, 1 / values[i]));
        }
        
        vector<double> ans;
        for(auto& ele: queries){
           double tmp = bfs(map_[ele[0]], map_[ele[1]]);
           ans.push_back(tmp);
        } 
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<string>> equations;
    equations.push_back(vector<string>{"a", "b"});
    equations.push_back(vector<string>{"b", "c"});
    vector<double> values{2.0, 3.0};
    vector<vector<string>> queries{vector<string>{"a", "c"}, vector<string>{"c", "b"}};
    vector<double> ans = s.calcEquation(equations, values, queries);
    for(auto a: ans){
        cout << a << " ";
    }
    cout <<endl;
}