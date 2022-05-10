//
//  11651 - 좌표 정렬하기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/10.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
pair<int, int> dot[100001];

bool cmp(pair<int ,int> a, pair<int, int> b){
    if(a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dot[i].X >> dot[i].Y;
    }
    sort(dot, dot + N, cmp);
    for(int i = 0; i < N; i++){
        cout << dot[i].X << " " << dot[i].Y << "\n";
    }
    return 0;
}
