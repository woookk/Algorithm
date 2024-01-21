//
//  2529 - 부등호.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/20.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int k;
string str = "", maxValue = "-1", minValue = "9999999999";

vector<bool> used(10, 0);

void solve(vector<char> &op, int prev, int depth) {
    if (depth == k + 1) {
        minValue = min(minValue, str);
        maxValue = max(maxValue, str);
        return;
    }
    
    if (op[depth - 1] == '>') {
        for (int i = 0; i < prev; i++) {
            if (used[i]) continue;
            used[i] = true;
            str += (char) (i + '0');
            solve(op, i, depth + 1);
            used[i] = false;
            str.erase(depth, 1);
        }
        return;
    }
    
    for (int i = prev + 1; i < 10; i++) {
        if (used[i]) continue;
        used[i] = true;
        str += (char) (i + '0');
        solve(op, i, depth + 1);
        used[i] = false;
        str.erase(depth, 1);
    }
}

int main() {
    FASTIO
    cin >> k;
    vector<char> op(k);
    for (int i = 0; i < k; i++) {
        cin >> op[i];
    }
    for (int i = 0; i < 10; i++) {
        used[i] = true;
        str += (char) (i + '0');
        solve(op, i, 1);
        used[i] = false;
        str.erase(0, 1);
    }
    cout << maxValue << "\n" << minValue << "\n";
    return 0;
}

/*
    두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열 A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다.
    부등호 기호 앞 뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다.
    제시된 k개의 부등호 순서를 만족하는 (k + 1)자리의 정수 중에서 최댓값과 최솟값을 찾아야한다.
 
    백트래킹 이용해서 부등호에 따라서 이전값보다 큰 경우, 작은 경우만 진행하는 방식으로 풀이
 */
