//C++
#include <bits/stdc++.h>
using namespace std;
set<string> a;

int main()
{
    string s,s1;
    while(cin >> s){
        if(s == "*") break;
        a.insert(s);
    }
    while(cin >> s1){
        if(s1 == "***") break;
        else if(s1 == "find"){
            string s2; cin >> s2;
            if(a.find(s2) != a.end()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(s1 == "insert"){
            string s2; cin >> s2;
            if(a.find(s2) != a.end()) cout << 0 << endl;
            else{
                cout << 1 << endl;
                a.insert(s2);
            }
        }

    }
    return 0;
}
