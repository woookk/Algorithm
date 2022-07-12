//
//  18870 - 좌표 압축.cpp
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
int X[1000001];
vector<int> tmp, uni;

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i];
        tmp.push_back(X[i]);
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < N; i++){
        if(i == 0 || tmp[i - 1] != tmp[i]){
            uni.push_back(tmp[i]);
        }
    }
    for(int i = 0; i < N; i++){
        cout << lower_bound(uni.begin(), uni.end(), X[i]) - uni.begin() << " ";
    }
    return 0;
}
