//
//  12865 - 평범한 배낭.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
pair<int ,int> item[101];
int d[101][100001];

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else
        return a.first < b.first;
}
int main(){
    FASTIO;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> item[i].first >> item[i].second;
    }
    sort(item + 1, item + N + 1, cmp);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(j >= item[i].first) d[i][j] = max(d[i - 1][j], d[i - 1][j - item[i].first] + item[i].second);
            else d[i][j] = d[i - 1][j];
        }
    }
    cout << d[N][K];
    return 0;
}
