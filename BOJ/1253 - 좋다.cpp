//
//  1253 - 좋다.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
int A[2001];

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    for(int i = 0; i < N; i++){
        int l = 0, r = N - 1;
        while(l < r){
            if(l == i){
                l++;
                continue;
            }
            if(r == i){
                r--;
                continue;
            }
            if(A[i] > A[l] + A[r]) l++;
            else if(A[i] == A[l] + A[r]){
                ans++;
                break;
            }
            else {
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
