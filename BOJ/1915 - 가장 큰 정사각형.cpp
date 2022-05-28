//
//  1915 - 가장 큰 정사각형.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/28.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m, ans;
int arr[1001][1001];
int d[1001][1001];

int main(){
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j]){
                d[i][j] = min({d[i - 1][j], d[i - 1][j - 1], d[i][j - 1]}) + 1;
                ans = max(d[i][j], ans);
            }
        }
    }
    cout << ans * ans;
    return 0;
}
