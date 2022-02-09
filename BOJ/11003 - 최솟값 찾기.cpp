//
//  11003 - 최솟값 찾기.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/09.
//

#include <iostream>
#include <deque>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int main(){
    FASTIO;
    int N, L;
    cin >> N >> L;
    deque<pair<int, int>> dq;
    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        while(!dq.empty() && dq.back().X > tmp)
            dq.pop_back();
        dq.push_back({tmp, i});
        while(i - dq.front().Y >= L)
            dq.pop_front();
        cout << dq.front().X << " ";
    }
    return 0;
}
