#include <bits/stdc++.h>
using namespace std;

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = gb.size()*2;
    int max = -9999999, min = 9999999;
    queue<int> q;
    vector<int> ans;    
    vector<int> status(n+1);
    vector<vector<int>> adj(n+1);
    for(int i = 0; i <= n; i++) {
        status[i] = 0;
    }
    for(int i = 0; i < gb.size(); i++) {
        adj[gb[i][0]].push_back(gb[i][1]);
        adj[gb[i][1]].push_back(gb[i][0]);
    }
    for(int i = 1; i <= n; i++) {
        if(status[i] == 1)
            continue;
        int count = 1;
        status[i] = 1;
        q.push(i);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto el : adj[x]) {
                if(status[el] == 1) {
                    continue;
                }
                status[el] = 1;
                count++;
                q.push(el);
            }
        }
        if(count == 1)
            continue;
        if(max < count)
            max = count;
        if(min > count)
            min = count;
    }
    ans.push_back(min);
    ans.push_back(max);
    return ans;
}

int main() {
    vector<vector<int>> edges = {{1,6}, {2,7}, {3,8}, {4,9}, {2,6}};
    vector<int> ans = componentsInGraph(edges);
    for(auto x : ans)
        cout << x << endl;
    return 0;
}