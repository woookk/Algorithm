//
//  1717 - 집합의 표현.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/07.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e6 + 5;

int n, m;
vector<int> parent(MAX);

int getParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

bool isEqual(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) {
        return true;
    }
    return false;
}

int main() {
    FASTIO
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            unionParent(a, b);
        }
        else {
            if (isEqual(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

/*
    초기에 n + 1개의 집합 {0}, {1}, ..., {n}이 존재.
    여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
 
    집합을 표현하는 프로그램 작성
 
    유니온파인드 알고리즘을 사용하여 문제 해결할 수 있다.
    
 */
