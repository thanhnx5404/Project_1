//C++
#include <bits/stdc++.h>
using namespace std;

bool check_Parenthesis(string s){
    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else if(s[i] == ')'){
            if(st.empty()) return false;
            char c = st.top();
            if(c != '(') return false;
            st.pop();
        }
        else if(s[i] == ']'){
            if(st.empty()) return false;
            char c = st.top();
            if(c != '[') return false;
            st.pop();
        }
        else if(s[i] == '}'){
            if(st.empty()) return false;
            char c = st.top();
            if(c != '{') return false;
            st.pop();
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    if(check_Parenthesis(s)) cout << 1;
    else cout << 0;
    return 0;
}
