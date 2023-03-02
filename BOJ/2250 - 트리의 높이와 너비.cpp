//
// Created by 민병욱 on 2023/03/02.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

struct node_ {
    int left;
    int right;
    int value;
    int depth;
};

int N;
int p, l, r;
int root;
struct node_ node[10001];
int cnt;

bool isRoot[10001];
int level, width;

bool cmp(struct node_ nodeA, struct node_ nodeB) {
    if (nodeA.depth == nodeB.depth) {
        if (nodeA.value > nodeB.value) return true;
        return false;
    }
    if (nodeA.depth < nodeB.depth) return true;
    return false;
}

void inorder(int cur, int depth) {
    if (cur == -1) return;
    inorder(node[cur].left, depth + 1);
    node[cur].value = ++cnt;
    node[cur].depth = depth;
    inorder(node[cur].right, depth + 1);
}

int main() {
    FASTIO
    cin >> N;
    fill(isRoot, isRoot + N + 1, true);
    for (int i = 0; i < N; i++) {
        cin >> p >> l >> r;
        node[p].left = l;
        node[p].right = r;

        if (l != -1) isRoot[l] = false;
        if (r != -1) isRoot[r] = false;
    }

    for (int i = 1; i <= N; i++) {
        if (isRoot[i]) {
            root = i;
        }
    }

    inorder(root, 1);

    sort(node + 1, node + N + 1, cmp);

    for (int i = 1; i <= cnt; i++) {
        int depth = node[i].depth;
        int idx = i;
        while (node[idx].depth == depth) {
            idx++;
        }
        int diff;
        if (i != idx)
            diff = node[i].value - node[idx - 1].value + 1;
        else
            diff = 1;
        if (diff > width) {
            width = diff;
            level = node[i].depth;
        }
    }

    cout << level << " " << width;
    return 0;
}