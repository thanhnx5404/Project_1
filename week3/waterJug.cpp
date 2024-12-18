#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return UCLN(b,a%b);
}

int minSteps(int a, int b, int c){
    if((c % UCLN(a,b) != 0) || c > a + b) return -1;
    queue<pair<pair<int,int>,int>> q;
    set<pair<int,int>> visited;
    q.push({{0,0},0});
    visited.insert({0,0});
    while(!q.empty()){
        auto tmp = q.front().first;
        int x = tmp.first;
        int y = tmp.second;
        int steps = q.front().second;
        q.pop();
        if(x == c || y == c || x+y == c) return steps;
        set<pair<int,int>> s = {
            {a,y},
            {x,b},
            {x,0},
            {0,y},
            {x - min(x,b-y), y + min(x,b-y)},
            {x + min(y,a-x), y - min(y,a-x)}
        };
        for(auto i : s){
            if(visited.find(i) == visited.end()){
                visited.insert(i);
                q.push({i,steps+1});
            }
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a,b,c;
    cin >> a >> b >> c;
    cout << minSteps(a,b,c);
    return 0;
}
