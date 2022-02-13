//
//  16938 - 캠프 준비.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, L, R, X;
int A[15];
int problem[15];
int ans;

void combination(int start, int depth, int num){
    if(depth == num){
        int sum = 0;
        for(int i = 0; i < num; i++){
            sum += problem[i];
        }
        if(sum < L || sum > R) return;
        if(problem[num-1] - problem[0] < X) return;
        ans++;
        return;
    }
    for(int i = start; i < N; i++){
        problem[depth] = A[i];
        combination(i+1, depth+1, num);
    }
}
int main(){
    FASTIO;
    cin >> N >> L >> R >> X;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    for(int i = 2; i <= N; i++){
        combination(0, 0, i);
    }
    cout << ans;
    return 0;
}
