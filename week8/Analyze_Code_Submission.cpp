#include <bits/stdc++.h>
using namespace std;

int total_number_submiss = 0;
map<string,int> mp1;
unordered_map<string,unordered_map<string,int>> mp2;
unordered_map<string,int> mp3;
vector<int> vt(86400,0);

int to_s(const string &s){
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    while(1){
        string input;
        getline(cin, input);
        if(input == "#") break;
        string userID, problemID, timePoint, status;
        int point;
        stringstream ss(input);
        ss >> userID >> problemID >> timePoint >> status >> point;

        total_number_submiss++;

        if(status == "ERR") mp1[userID]++;

        if(mp2[userID][problemID] < point){
            mp3[userID] += point - mp2[userID][problemID];
            mp2[userID][problemID] = point;
        }
        
        int time = to_s(timePoint);
        vt[time]++;
    }
    
    int S[86400];
    S[0] = vt[0];
    for(int i = 1; i < 86400; i++){
        S[i] = S[i-1] + vt[i];
    }

    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "?total_number_submissions") cout << total_number_submiss << endl;
        else if(s == "?number_error_submision"){
            int cnt = 0;
            for(auto x : mp1){
                cnt += x.second;
            }
            cout << cnt << endl;
        }
        else if(s == "?number_error_submision_of_user"){
            string tmp;
            cin >> tmp;
            cout << mp1[tmp] << endl;
        }
        else if(s == "?total_point_of_user"){
            string tmp; 
            cin >> tmp;
            cout << mp3[tmp] << endl;
        }
        else if(s == "?number_submission_period"){
            string time1, time2;
            cin >> time1 >> time2;
            int tmp1 = to_s(time1);
            int tmp2 = to_s(time2);
            cout << S[tmp2] - S[tmp1-1] << endl;
        }
    }
    return 0;
}