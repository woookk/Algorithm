//
//  2302 - 극장 좌석.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/20.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> v = {0};
int d[41];

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(N + 1);
    
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= N; i++){
        d[i] = d[i - 1] + d[i - 2];
    }
    int ans = 1;
    for(int i = 1; i < v.size(); i++){
        ans *= d[v[i] - v[i - 1] - 1];
    }
    cout << ans;
    return 0;
}
