//
//  1780 - 종이의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/04.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int arr[2500][2500];
int cnt[3];

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(arr[x][y] != arr[i][j])
                return false;
        }
    }
    return true;
}

void func(int x, int y, int N){
    if(check(x, y, N)){
        cnt[arr[x][y] + 1] += 1;
        return;
    }
    int n = N / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(x + i * n, y + j * n, n);
        }
    }
}
int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    func(0, 0, N);
    for(int i = 0; i < 3; i++){
        cout << cnt[i] << "\n";
    }
    
    return 0;
}
