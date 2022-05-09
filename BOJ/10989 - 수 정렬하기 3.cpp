//
//  10989 - 수 정렬하기 3.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/09.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, num;
int arr[10001];

int main(void) {
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        arr[num]++;
    }
    for(int i = 1; i <= 10000; i++){
        while(arr[i]){
            cout << i << '\n'; arr[i]--;
        }
    }
    return 0;
}
