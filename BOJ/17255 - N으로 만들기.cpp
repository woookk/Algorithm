//
//  17255 - N으로 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/05.
//

#include <iostream>
#include <set>
#include <map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string N;
map<set<string>, int> visited;

void dfs(int left, int right, string now, set<string> temp) {
    if (now.length() >= N.length()) {
        if (now.compare(N) == 0) {
            visited[temp] = 1;
        }
        return;
    }
    if (left > 0) {
        temp.insert(N[left - 1] + now);
        dfs(left - 1, right, N[left - 1] + now, temp);
        temp.erase(N[left - 1] + now);
    }
    if (right < N.length() - 1) {
        temp.insert(now + N[right + 1]);
        dfs(left, right + 1, now + N[right + 1], temp);
        temp.erase(now + N[right + 1]);
    }
}

int main() {
    FASTIO
    cin >> N;
    
    for (int i = 0; i < N.length(); i++) {
        string temp = "";
        set<string> st = {temp + N[i]};
        dfs(i, i, temp + N[i], st);
    }
    
    cout << visited.size();
    return 0;
}
