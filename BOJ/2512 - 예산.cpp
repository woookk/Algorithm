//
//  2512 - 예산.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/16.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;
int a[10001];

bool isPossible(int upper){
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] >= upper) sum += upper;
        else sum += a[i];
    }
    if(sum <= M){
        return true;
    }
    else return false;
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> M;
    int st = 0;
    int en = M;
    while(st <= en){
        int mid = (st + en) / 2;
        if(isPossible(mid)){
            ans = max(ans, mid);
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    int MX = *max_element(a, a + N);
    if(MX >= ans){
        cout << ans;
    }
    else {
        cout << MX;
    }
    return 0;
}
