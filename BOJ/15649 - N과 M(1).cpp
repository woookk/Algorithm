//
//  15649 - N과 M(1).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int arr[8];
int isused[10];

void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    func(0);
    return 0;
}
