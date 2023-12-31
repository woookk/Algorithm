//
//  12015 - 가장 긴 증가하는 부분 수열 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main() {
    FASTIO
    cin >> N;
    vector<int> L(N);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (idx == 0) L[idx++] = A;
        else {
            if (L[idx - 1] < A) L[idx++] = A;
            else {
                L[lower_bound(L.begin(), L.begin() + idx, A) - L.begin()] = A;
            }
        }
    }
    cout << idx;
    return 0;
}

/*
 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 
 각각의 인덱스에서 현재 값을 마지막 원소로 하는 증가하는 부분 수열의 길이를 저장하게 되면,
 이전의 원소들 중 자신보다 작은 원소의 값을 찾은 후 부분 수열의 길이를 +1을 해주게 되면 가장 긴 증가하는 부분 수열을 각각의 인덱스별로 구할 수 있다.
 이 때 시간복잡도는 O(N^2)이 걸리게 된다. 시간 복잡도 O(N^2)이면 N이 최대 1,000,000이므로 시간 초과 발생
 
 이전의 원소들을 탐색하는 과정을 lower_bound를 이용하여 O(logN)에 진행
 LIS를 만드는 과정에서 핵심은 LIS의 마지막 원소가 가능한 작을수록 더 긴 LIS를 생성할 수 있다는 것.
 그러므로 원소가 들어올 때, 현재 생성된 LIS의 마지막 원소보다 작은 경우, LIS에 들어갈 위치를 찾은 후 원소를 대체하는 방식
 */
