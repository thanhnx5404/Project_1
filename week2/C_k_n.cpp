//C++
#include <bits/stdc++.h>
using namespace std;
const long mod = 1000000007;
vector<vector<int>> vt;
int C(int k,int n){
    if(k==0||k==n) return 1;
    if(vt[k][n] != -1) return vt[k][n];
    vt[k][n] = (C(k-1,n-1)+C(k,n-1))%mod;
    return vt[k][n];
}
int main()
{
    int k,n; cin >> k >> n;
    vt.assign(k+1,vector<int>(n+1,-1));
    cout << C(k,n) << endl;
    return 0;
}

/*
//C++
#include <bits/stdc++.h>
using namespace std;
const long mod = 1000000007;
int C(int k,int n){
    vector<vector<int>> vt(k+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        vt[0][i] = 1;
    }
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j++){
            vt[i][j]=(vt[i-1][j-1]+vt[i][j-1])%mod;
        }
    }
    return vt[k][n];
}
int main()
{
    int k,n; cin >> k >> n;
    cout << C(k,n);
    return 0;
}
*/
