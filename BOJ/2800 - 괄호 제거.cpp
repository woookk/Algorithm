//
//  2800 - 괄호 제거.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/31.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

stack<int> s;
vector<pair<int, int>> bracket;
vector<string> ans;
bool isUsed[201];

int main() {
    FASTIO
    string equation;
    cin >> equation;
    
    for (int i = 0; i < equation.size(); i++) {
        if (equation[i] == '(') {
            s.push(i);
        }
        else if (equation[i] == ')') {
            int st = s.top();
            s.pop();
            int end = i;
            bracket.push_back({st, end});
        }
        else {
            continue;
        }
    }
    
    for (int i = 0; i < (1 << bracket.size()) - 1; i++) {
        string temp = "";
        fill(isUsed, isUsed + 201, 1);
        for (int j = 0; j < bracket.size(); j++) {
            if ((i % (1 << (j + 1))) / (1 << j) == 0) {
                isUsed[bracket[j].first] = 0;
                isUsed[bracket[j].second] = 0;
            }
        }
        for (int j = 0; j < equation.size(); j++) {
            if (isUsed[j] == 1) temp += equation[j];
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    
    string prev = "";
    for (auto v : ans) {
        if (prev.compare(v) == 0) {
            continue;
        }
        cout << v << "\n";
        prev = v;
    }
    return 0;
}
