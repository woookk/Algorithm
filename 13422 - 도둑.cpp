//
//  13422 - 도둑.cpp
//  cpp
//
//  Created by 병욱 민 on 3/14/25.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int N, M, K;
        cin >> N >> M >> K;
        int ans = 0;
        vector<int> houses(N + 1, 0);
        vector<int> sums(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> houses[i];
            sums[i] = sums[i - 1] + houses[i];
        }
        
        if (N == M) {
            if (sums[N] < K) {
                ans++;
            }
            cout << ans << "\n";
            continue;
        }
        
        for (int i = 1; i <= N; i++) {
            if (i + M - 1 <= N) {
                if (sums[i + M - 1] - sums[i - 1] >= K) {
                    continue;
                }
                ans++;
                continue;
            }
            if (sums[N] - sums[i - 1] + sums[M - (N - i + 1)] >= K) {
                continue;
            }
            ans++;
        }
        cout << ans << "\n";
        
    }
    return 0;
}

/*
 N개의 집이 순서대로 이웃하여 세워진 마을이 있다. 각각의 집은 순서대로 서로 이웃해 있으며, 첫 번째 집과 마지막 집 또한 이웃해 있다.
 이 마을 사람들은 각자 자신의 집에 돈을 보관한다.
 이 마을에 도둑이 들었다. 도둑은 이 마을에서 어떻게 도둑질을 할까 고민하다가, 빠르게 돈을 훔치고 달아나기 위해 M개의 연속된 집에서 돈을 훔치되, 돈을 훔칠 때는 각 집에 보관중인 돈을 전부 훔치기로 했다.
 만약 도둑이 이 망르에서 총 K원 이상의 돈을 훔친다면 자동 방범장치가 작동하여 도둑은 바로 붙잡히게 된다.
 
 도둑이 붙잡히지 않고 무사히 마을을 빠져나가기 위해 돈을 훔칠 M개의 연속된 집을 고르는 방법의 수를 구하시오.
 
 완전 탐색으로 풀이할 경우 각 테스트케이스에서 시간복잡도가 O(N * M) 10^10이 되므로 시간 초과가 발생한다.
 각각 집에서 훔칠 돈을 더하는 부분을 Prefix Sum을 이용해서 시간복잡도 O(1)을 통해서 계산하면 각 테스트케이스에서 시간복잡도가 O(N)이 된다.
 
 **N == M일 때는 모든 지점에서 시작할 필요 없다. 전체 합 한 번만 확인하면 된다**
 */
