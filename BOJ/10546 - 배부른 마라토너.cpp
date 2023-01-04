//
//  10546 - 배부른 마라토너.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/04.
//

#include <iostream>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main() {
    FASTIO
    cin >> N;
    unordered_map<string, int> st;
    
    for (int i = 0; i < N; i++) {
        string participant;
        cin >> participant;
        st[participant] += 1;
    }
    
    for (int i = 0; i < N - 1; i++) {
        string participant;
        cin >> participant;
        st[participant] -= 1;
    }
    
    for (auto p : st) {
        if (p.second > 0) {
            cout << p.first << "\n";
        }
    }
    return 0;
}
