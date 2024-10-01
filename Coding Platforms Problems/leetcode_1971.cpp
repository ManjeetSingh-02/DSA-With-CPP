// Find if Path Exists in Graph

// bool ans = false;
// vector<int> status(n);
// vector<vector<int>> adj(n);
// queue<int> q;
// for(int i = 0; i < n; i++)
//     status[i] = 0;
// for (int i = 0; i < edges.size(); i++)
// {
//     adj[edges[i][0]].push_back(edges[i][1]);
//     adj[edges[i][1]].push_back(edges[i][0]);
// }
// status[source] = 1;
// q.push(source);
// while (!q.empty())
// {
//     if(status[destination] == 1)
//     {
//         ans = true;
//         break;
//     }
//     int x = q.front();
//     q.pop();
//     for (auto el : adj[x])
//     {
//         if (status[el] == 1)
//             continue;
//         status[el] = 1;
//         q.push(el);
//     }
// }    
// return ans;