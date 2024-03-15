//
//  8111 - 0과 1.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        
        if (N == 1) {
            cout << "1\n";
            continue;
        }
        
        vector<bool> visited(N + 1, false);
        vector<pair<int, char>> prev(N + 1, {-1, '1'});
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        bool find = false;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (int i = 0; i < 2; i++) {
                int nx = (cur * 10 + i) % N;
                if (visited[nx]) continue;
                
                prev[nx].first = cur;
                prev[nx].second = i + '0';
                
                if (nx == 0) {
                    find = true;
                    break;
                }
                visited[nx] = true;
                q.push(nx);
            }
        }
        
        if (find) {
            string ans = "";
            int number = 0;
            while (number != -1) {
                ans += prev[number].second;
                number = prev[number].first;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
        else {
            cout << "BRAK\n";
        }
    }
    return 0;
}

/*
 폴란드 왕자 구사과는 다음과 같은 수를 좋아한다.
 - 0과 1로만 이루어져 있어야 한다.
 - 1이 적어도 하나 있어야 한다.
 - 수의 길이가 100 이하이다.
 - 수가 0으로 시작하지 않는다.
 자연수 N이 주어졌을 때, N의 배수 중에서 구사과가 좋아하는 수를 구하는 프로그램을 작성 (그러한 수가 없다면 BRAK을 출력)
 
 1부터 시작해서 0, 1을 하나씩 붙이는 방식은 시간 복잡도가 O(2^100)이므로 시간초과가 발생한다. 또한 값의 범위가 100자리까지이므로 오버플로우가 발생한다.
 이를 방지하기 위해서 % N으로 나눈 수에 대해 BFS를 진행하고 각각의 수에서 이전 수를 저장하고 붙여준 수를 복구하는 방식으로 풀이 진행
 */
