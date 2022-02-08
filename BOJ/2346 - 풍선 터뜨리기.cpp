//
//  2346 - 풍선 터뜨리기.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/08.
//

#include <iostream>
#include <deque>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    int N;
    cin >> N;
    deque<pair<int, int>> dq;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        dq.push_back({i+1, tmp});
    }
    while(!dq.empty()){
        auto cur = dq.front();
        int idx = cur.first;
        int mv = cur.second;
        cout << idx << " ";
        dq.pop_front();
        if(mv > 0){
            for(int i = 0; i < mv - 1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int i = 0; i < mv * -1; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
