//
//  28703 - Double It.cpp
//  cpp
//
//  Created by 민병욱 on 2023/10/09.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, maxValue;
int ans;

int main() {
    FASTIO
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        maxValue = max(maxValue, A);
        pq.push(A);
    }
    
    int curValue = maxValue;
    ans = curValue - pq.top();
    while (pq.top() < maxValue) {
        int minValue = pq.top();
        pq.pop();
        
        ans = min(ans, curValue - minValue);
        curValue = max(curValue, minValue * 2);
        pq.push(minValue * 2);
    }
    cout << min(ans, curValue - pq.top());
    return 0;
}

/*
 양의 정수로 이루어진 길이가 N인 배열 A
 원하는 만큼 배열에서 원하는 수 하나를 골라서 2를 곱할 수 있을 때
 배열 A의 최댓값과 최솟값의 차이를 가능한 최솟값으로 구하시오.
 
 모든 값들을 두 배 해주는 순간부터 최댓값 - 최솟값이 최소가 될 수 없음.
 각각 1/2를 곱해준 것이 더 작으므로
 
 따라서 초기 최댓값보다 작은 값들까지만 *2를 곱해준 후 확인
 */
