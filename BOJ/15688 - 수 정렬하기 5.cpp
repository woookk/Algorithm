//
//  15688 - 수 정렬하기 5.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/10.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int freq[20000001];

int main(void) {
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        freq[tmp + 1000000]++;
    }
    for(int i = 0; i <= 2000000; i++){
        while(freq[i]--){
            cout << i - 1000000 << "\n";
        }
    }
    return 0;
}

