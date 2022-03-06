//
//  15652 - N과 M (4).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int arr[8];

void func(int start, int depth){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i <= N; i++){
        arr[depth] = i;
        func(i, depth + 1);
    }
}
int main(){
    FASTIO;
    cin >> N >> M;
    func(1, 0);
    return 0;
}
