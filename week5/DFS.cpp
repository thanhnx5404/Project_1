//C++ 
#include <bits/stdc++.h> 
using namespace std;
void DFS(int start,vector<set<int>>& vt,vector<bool>& visited){
    cout << start << " ";
    visited[start] = true;
    for(int v : vt[start]){
        if(visited[v] == false){
            DFS(v,vt,visited);
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
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        vt[u].insert(v);
        vt[v].insert(u);
    }
    DFS(1,vt,visited);
    return 0;
}