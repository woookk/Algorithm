//
//  13414 - 수강신청.cpp
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
#define X first
#define Y second

int K, L;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    return a.Y < b.Y;
}

int main(){
    FASTIO
    cin >> K >> L;
    unordered_map<string, int> signup;
    for(int i = 0; i < L; i++){
        string snum;
        cin >> snum;
        signup[snum] = i;
    }
    vector<pair<string, int>> slist(signup.begin(), signup.end());
    sort(slist.begin(), slist.end(), cmp);
    
    K = min(K, (int)slist.size());
    
    for(int i = 0; i < K; i++){
        cout << slist[i].X << "\n";
    }
    return 0;
}
