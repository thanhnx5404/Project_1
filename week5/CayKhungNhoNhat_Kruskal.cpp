//C++ 
#include <bits/stdc++.h> 
using namespace std;
struct T{
    int u,v,w;
    bool operator < (const T& other) const{
        return w < other.w;
    }
};
vector<int> parent,Rank;

int findRoot(int u){
    if(parent[u] != u){
        parent[u] = findRoot(parent[u]);
    }
    return parent[u];
}
bool checkChuTrinh(int u, int v){
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    if(rootU != rootV){
        if(Rank[rootU] < Rank[rootV]){
            parent[rootU] = rootV;
        }
        else if(Rank[rootU] > Rank[rootV]){
            parent[rootV] = rootU;
        }
        else{
            parent[rootV] = rootU;
            Rank[rootU]++;
        }
        return true;
    }
    return false;
}

int Kruskal(int n, vector<T>& vt){
    sort(vt.begin(),vt.end());
    parent.resize(n+1);
    Rank.resize(n+1,0);
    for(int i = 1; i <= n; i++) parent[i]=i;
    int countCanh = 0, countWeight = 0;
    for( const T& x : vt){
        if(checkChuTrinh(x.u,x.v)){
            countWeight += x.w;
            countCanh++;
            if(countCanh == n-1) break;
        }
    }
    return countWeight;
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m; cin >> n >> m;
    vector<T> vt(m);

    for(int i = 0; i < m; i++){
        cin >> vt[i].u >> vt[i].v >> vt[i].w;
    }

    int result = Kruskal(n,vt);
    cout << result;
    return 0;
}