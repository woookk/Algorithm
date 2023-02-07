#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> node[20001];
int dist[20001];
int ans;
int cnt;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        node[A].push_back(B);
        node[B].push_back(A);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nx: node[cur]) {
            if (dist[nx]) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] > dist[ans]) {
            ans = i;
            cnt = 1;
        }
        else if (dist[i] == dist[ans]) {
            cnt++;
        }
    }

    cout << ans << " " << dist[ans] - 1 << " " << cnt;
    return 0;
}
