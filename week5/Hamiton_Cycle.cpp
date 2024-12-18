//C++ 
#include <bits/stdc++.h> 
using namespace std;
int res = 0;
bool ok = false;
void Try(int k,int n,vector<set<int>>& vt,vector<bool>& visited){
    visited[k] = true;
    res += 1;
    for(int x : vt[k]){
        if(visited[x] == false){
            Try(x,n,vt,visited);
        }
    }
    if(res == n){
        if(vt[k].find(1) != vt[k].end()){
            ok = true;
            return;
        }
    }
    visited[k] = false; 
    res -= 1;   
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int T; cin >> T;
    while(T--){
        int n,m; cin >> n >> m;
        vector<set<int>> vt(n+1);
        vector<bool> visited(n+1,false);
        for(int i = 1; i <=m; i++){
            int u,v; cin >> u >> v;
            vt[u].insert(v);
            vt[v].insert(u);
        }
        Try(1,n,vt,visited);
        if(ok) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
