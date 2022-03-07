//
//  15656 - N과 M (7).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/07.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int num[7];
int arr[7];

void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        arr[k] = num[i];
        func(k+1);
    }
}
int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    sort(num, num + N);
    func(0);
    return 0;
}
