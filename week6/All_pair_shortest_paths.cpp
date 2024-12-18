#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7; 
int n, m;
vector<vector<int>> vt;

void floydWarshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (vt[i][k] < MOD && vt[k][j] < MOD)
                    vt[i][j] = min(vt[i][j], vt[i][k] + vt[k][j]);
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n >> m;
    vt.assign(n + 1, vector<int>(n + 1, MOD));

    for (int i = 1; i <= n; ++i) {
        vt[i][i] = 0; 
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vt[u][v] = min(vt[u][v], w); 
    }

    floydWarshall();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (vt[i][j] == MOD) {
                cout << -1 << " "; 
            } else {
                cout << vt[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
