//
//  10159 - 저울.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/16.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int adj[105][105];

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (adj[j][i] && adj[i][k]) {
                    adj[j][k] = 1;
                }
            }
         }
    }
    
    for (int i = 1; i <= N; i++) {
        int cnt = N - 1;
        for (int j = 1; j <= N; j++) {
            if (adj[i][j] || adj[j][i]) cnt--;
        }
        cout << cnt << "\n";
    }
    return 0;
}

/*
 무게가 서로 다른 N개의 물건. 물건은 1번 ~ N번까지 번호. 일부 물건 쌍에 대해 양팔 저울로 어떤 것이 더 무거운 것인지 측정한 결과표를 가지고 있다.
 이 결과표로부터 직접 측정하지 않은 물건 쌍의 비교 결과를 알아낼 수도 있고 알아내지 못할 수도 있다.
 물건의 개수 N과 일부 물건 쌍의 비교 결과가 주어졌을 때, 각 물건에 대해서 그 물건과의 비교 결과를 알 수 없는 물건의 개수를 출력하는 프로그램을 작성하시오.
 
 j > i && i > k -> j > k
 */
