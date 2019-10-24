#include <bits/stdc++.h>
using namespace std;
int col[1000001];
bool is_it_visited[1000001];
vector<int> adj[1000001];
int k, m, n, c, maxi, cl, mc;
void dfs(int v)
{
    is_it_visited[v] = true;
    c++;
    for (auto p : adj[v])
        if (!is_it_visited[p])
            dfs(p);
}
int getnum(int x, int y)
{
    return n * x + y;
}

int main()
{
    cin >> n >> m >> c;
    vector<int> input;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int color;
            cin >> color;
            col[getnum(i, j)] = color;
            input.push_back(getnum(i, j));
        }
    }
    for (auto it : input)
    {
        int x = it / n, y = it % n;
        if (y + 1 < n && col[getnum(x, y + 1)] == col[getnum(x, y)])
        {
            adj[getnum(x, y + 1)].push_back(it);
            adj[it].push_back(getnum(x, y + 1));
        }
        if (x + 1 < m && col[getnum(x + 1, y)] == col[getnum(x, y)])
        {
            adj[getnum(x + 1, y)].push_back(it);
            adj[it].push_back(getnum(x + 1, y));
        }
    }
    for (auto it : input)
    {
        if (!vis[it])
        {
            c = 0;
            dfs(it);
            if (c > maxi)
            {
                maxi = c;
                mc = col[it];
            }
        }
    }
    cout << maxi << " " << mc;
    return 0;
}
