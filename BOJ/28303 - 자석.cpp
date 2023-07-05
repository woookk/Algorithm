//
//  28303 - 자석.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/01.
//

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N, K;
int a[500005];
int minValue, minIdx;
int ans = INT_MIN;

int main() {
    FASTIO
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    minValue = a[1];
    minIdx = 1;
    for (int i = 2; i <= N; i++) {
        ans = max(ans, a[i] - minValue - abs(i - minIdx) * K);
        if (a[i] <= minValue) {
            minValue = a[i];
            minIdx = i;
        }
        else {
            if (a[i] <= minValue + K * abs(i - minIdx)) {
                minValue = a[i];
                minIdx = i;
            }
        }
    }
    
    minValue = a[N];
    minIdx = N;
    for (int i = N - 1; i >= 1; i--) {
        ans = max(ans, a[i] - minValue - abs(i - minIdx) * K);
        if (a[i] <= minValue) {
            minValue = a[i];
            minIdx = i;
        }
        else {
            if (a[i] <= minValue + K * abs(i - minIdx)) {
                minValue = a[i];
                minIdx = i;
            }
        }
    }
    cout << ans;
    return 0;
}

/*
 1번 ~ N번까지 일렬로 배열된 실험대가 있다.
 이 실험대의 i번 칸에는 에너지 상수 ai가 설정되어 있으며, 외부의 배터리와 연결되어 있다.
 
 실험대에 일자 모양 자석 하나 설치 -> 자석의 크기는 2부터 N까지 이하가 임의로 설정할 수 있으며, 한쪽 끝에 한 칸 크기의 N극이 있고 반대쪽 끝에 한 칸 크기 S극이 있다.
 
 자석의 양 극은 정확히 하나의 칸 위에 놓여야 한다.
 
 자석을 실험대에 설치하면 배터리의 에너지가 변하는데, 다음 3가지 현상이 동시에 발생
 
 1. N극이 놓인 칸의 에너지만큼 배터리 충전
 2. S극이 놓인 칸의 에너지마늠 배터리 소모
 3. N극 번호 - S극 번호 * K 만큼 배터리 소모 (차는 절댓값)
 
 
 */
