// Course Schedule

vector<int> indeg(numCourses);
vector<vector<int>> adj(numCourses);
queue<int> q;
for(int i = 0; i < numCourses; i++)
    indeg[i] = 0;
for(auto x : prerequisites) {
    adj[x[1]].push_back(x[0]);
    indeg[x[0]]++;
}
for(int i = 0; i < numCourses; i++) {
    if(indeg[i] == 0)
        q.push(i);
}
if(q.empty() == true)
    return false;
while (!q.empty())
{
    int x = q.front();
    q.pop();
    for (auto el : adj[x])
    {
        indeg[el]--;
        if(indeg[el] == 0)
            q.push(el);
    }
}
for(auto x : indeg) {
    if(x > 0)
        return false;
}
return true;