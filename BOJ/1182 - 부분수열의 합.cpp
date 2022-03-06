#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, S, cnt = 0;
int num[20];

void func(int n, int sum) {
    if (n == N) {
        if (sum == S) cnt++;
    return;
    }
    func(n + 1, sum);
    func(n + 1, sum + num[n]);
}

int main() {
    FASTIO;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    func(0, 0);
    if (S == 0) cout << cnt-1;
    else cout << cnt;
}
