//
//  14002 - 가장 긴 증가하는 부분 수열 4.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/20.
//

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[1001], d[1001], pre[1001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    fill(d, d + N, 1);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(A[i] > A[j]) {
                if(d[i] < d[j] + 1){
                    d[i] = d[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    int maxi = 1, maxd = d[1];
    for(int i = 2; i <= N; ++i){
        if(maxd < d[i]){
          maxi = i;
          maxd = d[i];
        }
    }
    deque<int> ans;
    int cur = maxi;
    while(cur){
        ans.push_front(A[cur]);
        cur = pre[cur];
    }
    cout << ans.size() << "\n";
    for(auto c : ans) {
        cout << c << " ";
    }
    return 0;
}
