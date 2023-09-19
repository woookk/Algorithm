//
//  1613 - 역사.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/19.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, k, s;
int adj[405][405];

int main() {
    FASTIO
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (adj[j][i] && adj[i][k]) {
                    adj[j][k] = 1;
                }
            }
        }
    }
    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        if (adj[a][b]) {
            cout << -1 << "\n";
        }
        else if (adj[b][a]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}

/*
 역사적 사건들의 전후 관계를 잘 알고 있다.
 일부 사건들의 전후 관계가 주어질 때, 주어진 사건들의 전후 관계도 알 수 있을까? 이를 해결하는 프로그램을 작성해보자.
 
 i > j, j > k -> i > k
 */
