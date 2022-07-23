//
//  11660 - 구간 합 구하기 5.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/24.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int board[1025][1025];
int d[1025][1025];

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
            d[i][j] = d[i][j - 1] + board[i][j];
        }
    }
    
    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i = x1; i <= x2; i++){
            sum += (d[i][y2] - d[i][y1 - 1]);
        }
        cout << sum << "\n";
    }
    return 0;
}
