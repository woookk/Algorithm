//
//  11054 - 가장 긴 바이토닉 부분 수열.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/27.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;

int main () {
    FASTIO
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> leftSubsequence(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                leftSubsequence[i] = max(leftSubsequence[j] + 1, leftSubsequence[i]);
            }
        }
    }
    
    vector<int> rightSubsequence(N, 1);
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (A[i] > A[j]) {
                rightSubsequence[i] = max(rightSubsequence[j] + 1, rightSubsequence[i]);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        ans = max(ans, leftSubsequence[i] + rightSubsequence[i] - 1);
    }
    cout << ans;
    return 0;
}

/**
 
 수열 A가 주여졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성
 바이토닉 수열: 어떤 수 Sk를 기준으로 S1 < ... < Sk-1 < Sk > Sk+1 > ... > SN
 
 왼쪽부터 증가하는 부분 수열 길이 각 인덱스 별로 구하고
 오른쪽부터 증가하는 부분 수열 길이 각 인덱스 별로 구한 후
 각각의 인데긋에서 두 부분 수열 길이 더해주는 방식으로 바이토닉 부분 수열 길이 구할 수 있다.
 
 N^2으로 증가하는 부분 수열의 길이 각각 N^2으로 구할 수 있다.
 시간복잡도 O(N^2)
 
 시간복잡도 상 개선할 부분
 이전에 자기보다 작은 원소 찾는 부분을 이분탐색 이용해서 시간복잡도 줄일 수 있다.
 시간복잡도 O(NlogN)에 해결 가능
 최장 증가하는 부분 수열 문제에서 많이 사용하는 방식
 */
