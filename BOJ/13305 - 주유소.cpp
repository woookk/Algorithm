//
//  13305 - 주유소.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/28.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N;
ll ans;

int main() {
    FASTIO
    cin >> N;
    vector<ll> dist(N, 0);
    for (int i = 1; i < N; i++) {
        cin >> dist[i];
    }
    
    vector<ll> gasStation(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> gasStation[i];
    }
    
    ll minPrice = gasStation[0];
    
    for (int i = 0; i < N - 1; i++) {
        minPrice = min(minPrice, gasStation[i]);
        ans += minPrice * dist[i + 1];
    }
    cout << ans;
    return 0;
}

/**
    어떤 나라에 N개의 도시가 존재
    제일 왼쪽의 도시에서 제일 오른쪽의 도시로 자동차를 이용하여 이동
    처음 출발할 때 자동차에는 기름이 없어서 기름을 넣고 출발하여야 하고 각 도시에는 단 하나의 주유소가 있으며, 도로를 이용하여 이동할 때 1km마다 1리터의 기름을 사용
    각 도시에 있는 주유소의 기름 가격과, 각 도시를 연결하는 도로의 길이를 입력으로 받아 제일 왼쪽 도시에서 제일 오른쪽 도시로 이동하는 최소의 비용을 계산
    
    앞에서부터 가장 가격이 싼 주유소 저장해놓고 업데이트해나가는 방식으로 접근
    시간복잡도 O(N)에 풀이 가능
 
    풀이 시 곱해지는 값도 long long type으로 처리해야 오버플로우 발생하지 않음.
 */
