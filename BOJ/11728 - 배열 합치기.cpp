//
//  11728 - 배열 합치기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/04.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int A[1000001], B[1000001], ans[1000001];

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++)
        cin >> A[i];
    for(int i = 0 ; i < M; i++)
        cin >> B[i];
    int aidx = 0, bidx = 0;
    for(int i = 0; i < N + M; i++){
        if(bidx == M) ans[i] = A[aidx++];
        else if (aidx == N) ans[i] = B[bidx++];
        else if (A[aidx] <= B[bidx]) ans[i] = A[aidx++];
        else ans[i] = B[bidx++];
    }
    for(int i = 0; i < N + M; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
