//
//  4356 - 별자리 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/28.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
pair<double, double> stars[101];
bool isMST[101];
int cnt;
double ans;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> stars[i].X >> stars[i].Y;
    }
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    isMST[0] = true;
    for (int i = 1; i < N; i++) {
        double dist = distance(stars[0].X, stars[0].Y, stars[i].X, stars[i].Y);
        pq.push({dist, i});
    }
    
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = true;
        ans += cur.X;
        cnt++;
        
        for (int i = 0; i < N; i++) {
            if (isMST[i]) continue;
            pq.push({distance(stars[cur.Y].X, stars[cur.Y].Y, stars[i].X, stars[i].Y), i});
        }
    }
    cout << ans;
    return 0;
}
