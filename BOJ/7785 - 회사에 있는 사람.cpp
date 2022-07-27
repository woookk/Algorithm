//
//  7785 - 회사에 있는 사람.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/27.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;

int main(){
    FASTIO
    cin >> n;
    unordered_set<string> set;
    for(int i = 0; i < n; i++){
        string name, log;
        cin >> name >> log;
        if(log.compare("enter") == 0){
            set.insert(name);
        }
        else {
            set.erase(name);
        }
    }
    vector<string> ans;
    for(auto s: set){
        ans.push_back(s);
    }
    // vector<string> ans(set.begin(), s.end()); iterator를 이용해 깔끔하게 담을 수 있다.;
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto v: ans){
        cout << v << "\n";
    }
    return 0;
}
