//
//  9934 - 완전 이진 트리.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/07.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int K;
int arr[1024];
vector<int> tree[10];

void insert(int depth, int st, int end) {
    if (st >= end) {
        return;
    }
    int mid = (st + end) / 2;
    tree[depth].push_back(arr[mid]);
    insert(depth + 1, st, mid);
    insert(depth + 1, mid + 1, end);
}

int main() {
    FASTIO
    cin >> K;
    for (int i = 0; i < (1 << K) - 1; i++) {
        cin >> arr[i];
    }
    insert(0, 0, (1 << K) - 1);
    
    for (int i = 0; i < K; i++) {
        for(int j = 0; j < tree[i].size(); j++) {
            cout << tree[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
