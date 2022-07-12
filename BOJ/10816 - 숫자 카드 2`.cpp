//
//  10816 - 숫자 카드 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/12.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);


int N, M;
int a[500001];

int upper_idx(int x){
    int st = 0;
    int en = N;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] > x){
            en = mid;
        }
        else st = mid + 1;
    }
    return st;
}

int lower_idx(int x){
    int st = 0;
    int en = N;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] >= x){
            en = mid;
        }
        else st = mid + 1;

    }
    return st;
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    cin >> M;
    while(M--){
        int tmp;
        cin >> tmp;
        cout << upper_idx(tmp) - lower_idx(tmp) << "\n";
        
    }
    return 0;
}
