//
//  1371 - 가장 많은 글자.cpp
//  cpp
//
//  Created by 병욱 민 on 3/15/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);



int main() {
    FASTIO
    string s;
    vector<int> numberOfAlphabets(26, 0);
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            numberOfAlphabets[s[i] - 'a']++;
        }
    }
    int max = *max_element(numberOfAlphabets.begin(), numberOfAlphabets.end());
    for (int i = 0; i < 26; i++) {
        if (numberOfAlphabets[i] == max) {
            cout << (char) ('a' + i);
        }
    }
    return 0;
}
