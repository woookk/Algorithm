//
//  21276 - 계보 복원가 호석.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/10.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
string name[1001];
unordered_map<string, int> map;

vector<int> adj[1001];
int deg[1001];
vector<int> root;
vector<int> child[1002];

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> name[i];
    }
    sort(name + 1, name + N + 1);
    
    for (int i = 1; i <= N; i++) {
        map[name[i]] = i;
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        string X, Y;
        cin >> X >> Y;
        adj[map[Y]].push_back(map[X]);
        deg[map[X]]++;
    }

    

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            root.push_back(i);
        }
    }

    cout << root.size() << "\n";
    for (int r : root) {
        cout << name[r] << " ";
    }
    cout << "\n";
    
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
        for (int c: adj[i]) {
            if (deg[c] - deg[i] == 1) child[i].push_back(c);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << name[i] << " " << child[i].size() << " ";
        for (int c : child[i]) {
            cout << name[c] << " ";
        }
        cout << "\n";
    }
    return 0;
}
