//
//  16165 - 걸그룹 마스터 준석이.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/28.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;

int main(){
    FASTIO;
    cin >> N >> M;
    string team, member;
    int mems;
    unordered_map<string, string> mTot;
    unordered_map<string, vector<string>> tTom;
    while(N--){
        cin >> team >> mems;
        while(mems--){
            cin >> member;
            mTot[member] = team;
            tTom[team].push_back(member);
        }
        sort(tTom[team].begin(), tTom[team].end());
    }
    
    int kind;
    string quiz;
    while(M--){
        cin >> quiz >> kind;
        if(kind){
            cout << mTot[quiz] << "\n";
        }
        else {
            for(auto v : tTom[quiz]){
                cout << v << "\n";
            }
        }
    }
    return 0;
}
