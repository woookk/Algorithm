//
//  1007 - 벡터 매칭.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/12.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int T;
int N;
pair<int, int> dot[21];
bool is_used[21];
double ans = 100000000;

double vectorSum() {
    long long x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (is_used[i]) {
            x += dot[i].X;
            y += dot[i].Y;
        } else {
            x -= dot[i].X;
            y -= dot[i].Y;
        }
    }
    return sqrt(x * x + y * y);
}

void dfs(int start, int depth) {
    if (depth == N / 2) {
        ans = min(ans, vectorSum());
        return;
    }
    for (int i = start; i < N; i++) {
        if (!is_used[i]) {
            is_used[i] = true;
            dfs(i + 1, depth + 1);
            is_used[i] = false;
        }
    }
    
}

int main() {
    FASTIO
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        cin >> N;
        ans = 100000000;
        for (int i = 0; i < N; i++) {
            cin >> dot[i].X >> dot[i].Y;
        }
        dfs(0, 0);
        cout << fixed;
        cout.precision(10);
        cout << ans << "\n";
    }
    return 0;
}

/*
 평면 상 N개의 점이 찍혀있고, 그 점의 집합을 P. P의 벡터 매칭은 벡터 집한인데, P의 한점에서 시작해서, 또 다른 점에서 끝나는 벡터 집합이다.
 P에 속하는 모든 점은 한 번 씩은 쓰여야 한다. 벡터 매칭에 있는 벡터의 개수는 P에 있는 점의 절반이다. 벡터 합의 길이의 최솟값을 출력하라.
 
 벡터 매칭에 있는 벡터의 개수가 P의 절반이면서 P에 속하는 모든 점이 한 번 씩은 쓰여야하므로 벡터 매칭은 점 P의 모든 점을 한 번씩 사용하여 만든 벡터들로 구성된다.
 벡터 합의 길이를 구할 때 각각의 점들은 벡터의 시작점이거나 끝점이므로 벡터 합을 구할 때 좌표에서 더해지거나 빼지게된다.
 
 시작점 10개를 고르는 경우의 수는 20 Choose 10이고 N이 최대일 경우에도 경우의 수가 약 100만정도이므로 시간초과가 발생하지 않는다.
 각각의 점들을 조합을 구현하여 is_used 배열로 10개를 선택한 후 벡터 합을 확인하여 최솟값을 구한다.
 
 실수: 벡터 합을 구하는 과정에서 x, y를 int로 선언하여 x, y 절대값이 100,000인 상황에서 제곱할 경우 오버플로우 발생. long long으로 선언.
 */
