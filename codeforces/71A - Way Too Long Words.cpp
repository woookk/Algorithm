//
// Created by 민병욱 on 2023/03/02.
//
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int k;
string word;

int main() {
    FASTIO
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> word;
        int len = word.length();
        if (len > 10) {
            cout << word[0] << len - 2 << word[len -1] << "\n";
        }
        else {
            cout << word << "\n";
        }
    }
    return 0;
}