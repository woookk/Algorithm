//
//  1027 - 고층 건물.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/06.
//

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int h[55];

int ans = INT_MIN;

void calc() {
    for (int cur = 1; cur <= N; cur++) {
        int numberOfBuilding = 0;
        for (int prev = 1; prev < cur; prev++) {
            bool isVisible = true;
            double a = (double) (h[cur] - h[prev]) / (cur - prev);
            
            for (int mid = prev + 1; mid < cur; mid++) {
                if (h[prev] + a * (mid - prev) <= h[mid]) {
                    isVisible = false;
                    break;
                }
            }
            if (isVisible) {
                numberOfBuilding++;
            }
        }
        for (int nx = cur + 1; nx <= N; nx++) {
            bool isVisible = true;
            double a = (double) (h[nx] - h[cur]) / (nx - cur);
            
            for (int mid = cur + 1; mid < nx; mid++) {
                if (h[cur] + a * (mid - cur) <= h[mid]) {
                    isVisible = false;
                    break;
                }
            }
            if (isVisible) {
                numberOfBuilding++;
            }
        }
        ans = max(ans, numberOfBuilding);
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    
    if (N == 1) {
        ans = 0;
    }
    else if (N == 2) {
        ans = 1;
    }
    else {
        calc();
    }
    cout << ans;
    return 0;
}

/*
    가장 많은 고층 빌딩이 보이는 고층 빌딩을 찾으려고 한다.
    빌딩 총 N개가 있는데, 빌딩은 선분으로 나타낸다. i번째 빌딩은 (i, 0)부터 (i, 높이)의 선분으로 나타낼 수 있다.
    고층 빌딩 A에서 다른 고층 빌딩 B가 볼 수 있는 빌딩이 되려면, 두 지붕을 잇는 선분이 A와 B를 제외한 다른 고층 빌딩을 지나거나 접하지 않아야한다.
 
    모든 점들(시작점, 끝점)에 대해 사이에 있는 모든 점 확인 -> O(N^3)
    
 */
