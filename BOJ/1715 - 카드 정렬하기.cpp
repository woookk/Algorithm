//
//  1715 - 카드 정렬하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/06.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
long long ans;

int main(){
    FASTIO
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans;
    return 0;
}
