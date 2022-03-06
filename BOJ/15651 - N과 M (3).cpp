//
//  15651 - N과 M (3).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int arr[8];

void func(int k){
    if(k == M){
        for(int i = 0; i < k; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        arr[k] = i;
        func(k + 1);
    }
}
int main(){
    FASTIO;
    cin >> N >> M;
    func(0);
    return 0;
}
