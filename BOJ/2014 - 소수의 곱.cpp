//
//  2014 - 소수의 곱.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int K, N;

int main() {
    FASTIO
    cin >> K >> N;
    vector<ll> prime(K);
    for (int i = 0; i < K; i++) {
        cin >> prime[i];
    }
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    map<ll, bool> visited;
    pq.push(1);
    visited[1] = true;
    
    ll maxValue = 1L;
    while (N--) {
        auto cur = pq.top();
        pq.pop();
        
        for (auto num: prime) {
            ll nx = cur * num;
            
            if (visited.count(nx)) continue;
            if (pq.size() > N && maxValue <= nx) continue;
            
            pq.push(nx);
            visited[nx] = true;
            maxValue = max(maxValue, nx);
        }
    }
    cout << pq.top();
    return 0;
}

/*
 K개의 소수가 있다. 이 소수들 중에서 몇 개를 곱해서 얻게 되는 수들이 있을 것이다. 소수들을 선택할 때는 같은 수를 선택해도 되며, 주어지는 소수 자체도 포함시키자.
 K개의 소수가 주어졌을 때, 이러한 소수의 곱들 중에서 N번째 수를 구하는 프로그램을 작성
 
 우선순위 큐를 활용해서 가장 작은 수에 주어진 소수들을 계속해서 곱하는 방식으로 풀이 진행
 이 때 풀이의 시간복잡도는 O(K * NlogN)이므로 시간초과가 발생하지 않는다.
 
 **매번 곱해지는 수가 많을 경우 메모리 초과가 발생할 수 있으므로 우선순위 큐의 사이즈가 N보다 클 경우에는 넣어주는 과정을 생략해 메모리를 효율적으로 사용하는 방식으로 풀이를 진행해야 한다.**
 **답은 2^31보다 작은 자연수로 int값의 범위 안에 들어오지만, 계산 과정에서 int 오버플로우가 발생할 경우 정답이 바뀌는 경우가 발생할 수 있다. (음수가 되거나 예상치 못한 결과 발생)**
 */
