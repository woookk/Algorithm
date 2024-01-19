//
//  11066 - 파일 합치기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/19.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX;
int T;

int main() {
    FASTIO
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        vector<int> file(K + 1);
        for (int i = 1; i <= K; i++) {
            cin >> file[i];
        }
        
        vector<vector<int>> dp(K + 2, vector<int> (K + 2, 0));
        for (int i = 1; i < K; i++) {
            for (int j = 1; i + j <= K; j++) {
                dp[j][j + i] = INF;
                int sum = 0;
                for (int k = j; k <= j + i; k++) {
                    sum += file[k];
                }
                for (int k = j; k <= i + j; k++) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum);
                }
            }
        }
        cout << dp[1][K] << "\n";
    }
    return 0;
}

/*
    소설을 여러 장으로 나누어 쓰는데, 각 장을 다른 파일에 저장.
    소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어있는 한 개의 파일을 만든다.
    이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 합쳐나가고, 최종적으로는 하나의 파일로 합친다.
    이 과정에서 두 개의 파일을 합칠 때 필요한 비용이 두 파일의 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.
 
    최종적인 한 개의 파일을 완성하는데 소설의 여러 장들이 연속이 되어야 하므로, 최종 결과물은 바뀌지 않지만 필요한 비용은 각 장들을 합치는 순서에 따라서 바뀌게 된다.
 
    구간을 두 구간으로 나누어 1 ~ k, k + 1 ~ K 각각의 그룹에서의 비용의 최솟값을 구한 뒤 더하는 방식으로 접근
    이 때, 각 구간의 최솟값을 다이나믹 프로그래밍을 이용하여 구하고 합치는데 필요한 비용은 구간의 시작부터 끝까지의 파일 크기의 합으로 구할 수 있다.
 */
