//
//  2295 - 세 수의 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int U[1001];
vector<int> two;

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> U[i];
    }
    sort(U, U + N);
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            two.push_back(U[i] + U[j]);
        }
    }
    sort(two.begin(), two.end());
    for(int i = N - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(two.begin(), two.end(), U[i] - U[j])){
                cout << U[i];
                return 0;
            }
        }
    }
    return 0;
}
