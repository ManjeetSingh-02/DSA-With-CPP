// Keys and Rooms

bool ans = true;
vector<int> status(rooms.size());
queue<int> q;
for(int i = 0; i < rooms.size(); i++)
    status[i] = 0;
status[0] = 1;
q.push(0);
while (!q.empty())
{
    int x = q.front();
    q.pop();
    for (auto el : rooms[x])
    {
        if (status[el] == 1)
            continue;
        status[el] = 1;
        q.push(el);
    }
}
for(auto x : status) {
    if(x == 0)
        ans = false;
}
return ans;