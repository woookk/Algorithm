//
//  1339 - 단어 수학.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int numberOfAlphabets = 26;

int N, ans;

int main() {
    FASTIO
    cin >> N;
    vector<int> alphabet(numberOfAlphabets, 0);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        int unit = 1;
        for (int j = (int) word.length() - 1; j >= 0; j--) {
            alphabet[word[j] - 'A'] += unit;
            unit *= 10;
        }
    }
    
    sort(alphabet.begin(), alphabet.end(), greater<>());
    for (int i = 9; i >= 0; i--) {
        ans += alphabet[9 - i] * i;
    }
    cout << ans;
    return 0;
}

/*
    단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다.
    이 떄, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다.
    같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안된다.
    N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.
 
    알파벳마다 각각 자릿수가 곱해진 값을 저장하고 값이 높은 알파벳부터 높은 숫자로 바꾸는 방식으로 풀이 진행 (그리디)
 */
