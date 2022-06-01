//
//  2166 - 다각형의 면적.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
double ans;
pair<long long, long long> dot[10001];

long long calc(const pair<long long, long long> &a, const pair<long long, long long> &b){
    return a.X * b.Y - a.Y * b.X;
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dot[i].X >> dot[i].Y;
    }
    for(int i = 1; i < N - 1; i++){
        ans += (double)calc({dot[i].X - dot[0].X, dot[i].Y - dot[0].Y}, {dot[i + 1].X - dot[0].X, dot[i + 1].Y - dot[0].Y}) / 2;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
    return 0;
}
