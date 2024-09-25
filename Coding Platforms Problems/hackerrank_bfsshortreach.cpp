#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    vector<int> status(n + 1);
    vector<int> distance(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> res;
    queue<int> q;
    for (int i = 0; i <= n; i++)
    {
        status[i] = 0;
        distance[i] = -1;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    status[s] = 1;
    distance[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto el : adj[x])
        {
            if (status[el] == 1)
            {
                continue;
            }
            status[el] = 1;
            distance[el] = distance[x] + 6;
            q.push(el);
        }
    }
    for (int i = 1; i < distance.size(); i++)
    {
        if (i != s)
        {
            res.push_back(distance[i]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}};
    vector<int> ans = bfs(4, 2, edges, 1);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}