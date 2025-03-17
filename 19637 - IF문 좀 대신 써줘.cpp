//
//  19637 - IF문 좀 대신 써줘.cpp
//  cpp
//
//  Created by 병욱 민 on 3/15/25.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;

int main() {
    FASTIO
    cin >> N >> M;
    vector<pair<int, string>> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i].Y >> v[i].X;
    }
    for (int i = 0; i < M; i++) {
        int num = 0, result = 0, st = 0, end = v.size() - 1;
        cin >> num;
        result = end;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (v[mid].X >= num) {
                end = mid - 1;
                result = mid;
                continue;
            }
            st = mid + 1;
        }
        cout << v[result].Y << "\n";
    }
    return 0;
}
