#include <bits/stdc++.h> 
using namespace std;

void BFS(int start,vector<set<int>>& vt,vector<int>& parent,vector<bool>& visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";
        for(int x : vt[tmp]){
            if(visited[x] == false){
                q.push(x);
                visited[x] = true;
                parent[x] = start;
            }
        }
    }
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m; cin >> n >> m;
    vector<set<int>> vt(n+1);
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        vt[u].insert(v);
        vt[v].insert(u);
    }
    for(int i = 1; i <= n; i++){
        if(parent[i] == 0){
            BFS(i,vt,parent,visited);
        }
        else continue;
    }
    return 0;
}