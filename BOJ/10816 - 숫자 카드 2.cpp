//
//  10816 - 숫자 카드 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/18.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;

int num[20000001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        num[tmp + 10000000]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        cout << num[tmp + 10000000] << " ";
    }
    return 0;
}
