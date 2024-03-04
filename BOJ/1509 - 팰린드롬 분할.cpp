//
//  1509 - 팰린드롬 분할.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/01.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string s;

int main() {
    FASTIO
    cin >> s;
    s = " " + s;
    N = (int) s.length();
    vector<vector<bool>> isPalindrome(N + 1, vector<bool>(N + 1, false));
    for (int i = 1; i <= N; i++) {
        isPalindrome[i][i] = true;
    }
    for (int i = 1; i < N; i++) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
        }
    }
    for (int i = 2; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            if (s[j] == s[i + j] && isPalindrome[j + 1][j + i - 1]) {
                isPalindrome[j][j + i] = true;
            }
        }
    }
    
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            if (isPalindrome[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[N - 1];
    return 0;
}

/*
 어떤 문자열을 팰린드롬으로 분할하려고 한다. 분할의 개수의 최솟값을 출력하는 프로그램을 작성
 
 다이나믹 프로그래밍을 이용하여 문제 풀이 진행
 팰린드롬 문자열에서 왼쪽과 오른쪽에 같은 문자를 추가한다면 생성된 문자열도 팰린드롬인 것을 이용하여 팰린드롬 문자열을 모두 구할 수 있다.
 길이가 1인 문자열은 팰린드롬, 길이가 2인 문자열은 둘이 서로 같다면 팰린드롬
 
 이후, 팰린드롬의 최소 개수를 구할 때 중간에 팰린드롬이 위치하는 모든 경우를 다 따져보면서 최소 경우를 업데이트하는 방식으로 풀이를 진행
 **0인덱스에서 1인덱스로 바꿔줬으므로 주의**
 */
