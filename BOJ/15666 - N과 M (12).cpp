//
//  15666 - N과 M (12).cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/08.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int num[8];
int arr[8];

void func(int start, int depth){
    if(depth == M){
        for(int i = 0; i < depth; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    for(int i = start; i < N; i++){
        if(tmp != num[i]){
            arr[depth] = num[i];
            tmp = arr[depth];
            func(i , depth + 1);
        }
    }
}
int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    func(0, 0);
    return 0;
}
