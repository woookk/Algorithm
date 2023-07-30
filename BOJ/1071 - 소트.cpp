//
//  1071 - 소트.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[55];

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    
    for (int i = 0; i < N - 1; i++) {
        int idx = i;
        if (A[idx] + 1 != A[idx + 1]) continue;
        
        int targetIdx = idx + 1;
        while (A[idx + 1] == A[targetIdx]) {
            targetIdx++;
        }
        
        if (targetIdx == N) { // 뒤에 다른 값 존재 X
            int startIdx = idx;
            while (A[idx] == A[startIdx]) {
                startIdx--;
            }
            swap(A[++startIdx], A[idx + 1]);
        }
        else {
            swap(A[targetIdx], A[idx + 1]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    return 0;
}

/*
 N개의 정수가 주어지면, 이것을 연속된 두 수가 연속된 값이 아니게 정렬(A[i] + 1 != A[i + 1])하는 프로그램을 작성
 가능한 것이 여러 가지라면 사전순으로 가장 앞서는 것을 출력
 
 각 인덱스에서 A[idx] + 1 == A[idx + 1]일 때 (정렬한 후)
 1) idx + 1 ~ N - 1까지 A[idx + 1]인 경우
    A[idx]과 같은 값을 가지는 최초 인덱스와 A[idx + 1]을 교환한다.
 2) 다른 값이 존재할 경우
    다른 값이 존재한다면 그 값과 A[idx + 1]을 교환.
 위 두 과정을 각각의 인덱스에서 반복해준다.
 */
