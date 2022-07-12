//
//  1920 - 수 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/12.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int A[100001];

bool Search(int x){
    int st, en, mid;
    st = 0; en = N - 1;
    while(st <= en){
        mid = (st + en) / 2;
        if(A[mid] == x) return 1;
        else if(A[mid] > x){
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    return 0;
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    cin >> M;
    while(M--){
        int x;
        cin >> x;
        cout << Search(x) << "\n";
    }
    return 0;
}
