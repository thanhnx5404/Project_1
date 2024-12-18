#include <bits/stdc++.h>
using namespace std;

int cnt_people = 0;
int max_ancestor = 0;
int k = 0;
map<string,int> dob;
map<string,vector<string>> mp1;
unordered_map<string,vector<string>> graph;
unordered_set<string> people;

// void solve(string code){
//     for(string x : mp1[code]){
//         if(x != "0000000"){
//             k++;
//             solve(x);
//         }
//         else{
//             max_ancestor = max(max_ancestor,k);
//             k--;
//         }   
//     }
// }

void solve(string code, int depth){
    if (code == "0000000") {
        max_ancestor = max(max_ancestor, depth);
        return;
    }
    for (string x : mp1[code]) {
        if (x != "0000000") solve(x, depth + 1);
    }
}

// int solve2(){
//     vector<pair<string,int>> degreeList;
//     for(const auto& person : people){
//         degreeList.emplace_back(person,graph.at(person).size());
//     }
//     sort(degreeList.begin(),degreeList.end(),[](const auto& a, const auto& b){
//         return a.second < b.second;
//     });

//     unordered_set<string> res;
//     unordered_set<string> visited;
//     for(const auto& [person,degree] : degreeList){
//         if(visited.find(person) == visited.end()){
//             res.insert(person);
//             for(const auto& x : graph.at(person)){
//                 visited.insert(x);
//             }
//             visited.insert(person);
//         }
//     }
//     return res.size();
// }

int solveMaxUnrelatedPeople() {
    // Tính bậc (degree) của mỗi đỉnh
    unordered_map<string, int> degree;
    for (const auto& [person, neighbors] : graph) {
        degree[person] = neighbors.size();
    }

    // Sắp xếp đỉnh theo bậc (degree) bằng priority_queue (min-heap)
    using PII = pair<int, string>; // {degree, person}
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    unordered_set<string> visited;

    for (const auto& [person, deg] : degree) {
        pq.emplace(deg, person);
    }

    // Tập hợp kết quả
    unordered_set<string> result;

    // Chọn tập độc lập tối đại
    while (!pq.empty()) {
        auto [deg, person] = pq.top();
        pq.pop();

        // Bỏ qua nếu đã thăm
        if (visited.find(person) != visited.end()) continue;

        // Thêm vào tập kết quả
        result.insert(person);

        // Đánh dấu các đỉnh kề là đã thăm
        for (const string& neighbor : graph[person]) {
            visited.insert(neighbor);
        }
        visited.insert(person); // Đánh dấu chính nó
    }

    // Trả về kích thước tập độc lập
    return result.size();
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    while(1){
        string input;
        getline(cin, input);
        if(input == "*") break;
        stringstream ss(input);
        string code, date_of_birth, father_code, mother_code, is_alive, region_code;
        ss >> code >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;
            
        cnt_people++;

        dob[date_of_birth]++;

        mp1[code] = {father_code,mother_code};
        
        people.insert(code);
        if(father_code != "0000000"){
            graph[code].push_back(father_code);
            graph[father_code].push_back(code);
        }
        if(mother_code != "0000000"){
            graph[code].push_back(mother_code);
            graph[mother_code].push_back(code);
        }
    }

    string s;
    while(cin >> s){
        if(s == "***") break;
        else if(s == "NUMBER_PEOPLE") cout << cnt_people << endl;
        else if(s == "NUMBER_PEOPLE_BORN_AT"){
            string tmp; cin >> tmp;
            cout << dob[tmp] << endl;
        }
        else if(s == "MOST_ALIVE_ANCESTOR"){
            string tmp; cin >> tmp;
            solve(tmp,0);
            cout << max_ancestor << endl;
            max_ancestor = 0;
            k = 0;
        }
        else if(s == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string date1,date2;
            cin >> date1 >> date2;
            auto startIt = dob.lower_bound(date1);
            auto endIt = dob.upper_bound(date2);
            int cnt = 0;
            for(auto it = startIt; it != endIt; it++){
                cnt += it->second;
            }
            cout << cnt << endl;
        }
        else if(s == "MAX_UNRELATED_PEOPLE"){
            cout << solveMaxUnrelatedPeople() << endl;
        }
    }
    return 0;
}