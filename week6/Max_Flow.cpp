//C++ 
#include <bits/stdc++.h> 

const int INF = INT_MAX;
using namespace std;

bool dfs(int u, int t, vector<vector<int>>& vt, vector<vector<int>>& a, vector<int>& parent) {
    if (u == t) return true; 
    for (int v : a[u]) {
        if (vt[u][v] > 0 && parent[v] == -1) {
            parent[v] = u;
            if (dfs(v, t, vt, a, parent))
                return true;
        }
    }
    return false;
}

int edmondsKarpDFS(int n, int s, int t, vector<vector<int>>& vt, vector<vector<int>>& a) {
    int max_flow = 0;
    vector<int> parent(n);

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = s;

        if (!dfs(s, t, vt, a, parent))
            break; 

        int flow = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, vt[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            vt[u][v] -= flow; 
            vt[v][u] += flow; 
        }
        max_flow += flow;
    }
    return max_flow;
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vt(n, vector<int>(n, 0));
    vector<vector<int>> a(n);

    int s, t;
    cin >> s >> t;
    s--; t--;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        vt[u][v] += w; 
        a[u].push_back(v); 
        a[v].push_back(u); 
    }

    int max_flow = edmondsKarpDFS(n, s, t, vt, a);
    cout << max_flow << endl;
    return 0;
}
