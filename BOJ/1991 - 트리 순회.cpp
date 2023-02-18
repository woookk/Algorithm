//
// Created by 민병욱 on 2023/02/19.
//
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int lc[31];
int rc[31];

void preorder(int cur) {
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char c, l, r;
        cin >> c >> l >> r;
        if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
        if (r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
    }

    preorder(1);
    cout << "\n";

    inorder(1);
    cout << "\n";

    postorder(1);
    cout << "\n";
    return 0;
}