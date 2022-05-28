//
//  10942 - 팰린드롬?.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/28.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int num[2001];
int d[2001][2001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= N; i++){
        d[i][i] = 1;
        if(num[i - 1] == num[i]) d[i - 1][i] = 1;
    }
    for(int gap = 2; gap < N; gap++){
        for(int i = 1; i <= N - gap; i++){
            int st = i, end = i + gap;
            if(num[st] == num[end] && d[st + 1][end - 1]) d[st][end] = 1;
        }
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        int st, end;
        cin >> st >> end;
        cout << d[st][end] << "\n";
    }
    return 0;
}
