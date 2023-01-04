//
//  2776 - 암기왕.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/04.
//

#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
int TC;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int N, M;
        cin >> N;
        set<int> st;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            st.insert(num);
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            int num;
            cin >> num;
            if (st.find(num) != st.end()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
