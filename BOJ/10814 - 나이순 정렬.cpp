//
//  10814 - 나이순 정렬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/10.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
pair<int, string> person[100001];

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> person[i].first >> person[i].second;
    }
    stable_sort(person, person + N, cmp);
    for(int i = 0; i < N; i++){
        cout << person[i].first << " " << person[i].second << "\n";
    }
}
