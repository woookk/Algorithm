//
//  14891 - 톱니바퀴.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/19.
//

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int K, ans;
bool isrotate[4];
deque<bool> dq[4];

void rotate(int num, int dir){
    if(!isrotate[num]){
        isrotate[num] = true;
        if(num == 0) {
            if(dq[num][2] != dq[num + 1][6] && !isrotate[num + 1]){
                rotate(num + 1, 1  - dir);
            }
            if(dir == 1){
                dq[num].push_front(dq[num].back());
                dq[num].pop_back();
            }
            else {
                dq[num].push_back(dq[num].front());
                dq[num].pop_front();
            }
        }
        else if (num == 3) {
            if(dq[num][6] != dq[num - 1][2] && !isrotate[num - 1]){
                rotate(num - 1, 1  - dir);
            }
            if(dir == 1){
                dq[num].push_front(dq[num].back());
                dq[num].pop_back();
            }
            else {
                dq[num].push_back(dq[num].front());
                dq[num].pop_front();
            }
        }
        else {
            if(dq[num][2] != dq[num + 1][6] && !isrotate[num + 1]){
                rotate(num + 1, 1  - dir);
            }
            if(dq[num][6] != dq[num - 1][2] && !isrotate[num - 1]){
                rotate(num - 1, 1  - dir);
            }
            if(dir == 1){
                dq[num].push_front(dq[num].back());
                dq[num].pop_back();
            }
            else {
                dq[num].push_back(dq[num].front());
                dq[num].pop_front();
            }
        }
    }
}

int main(){
    FASTIO;
    for(int i = 0; i < 4; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 8; j++){
            dq[i].push_back(tmp[j] - '0');
        }
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        fill(isrotate, isrotate + 4, 0);
        int num, dir;
        cin >> num >> dir;
        if(dir == -1) dir = 0;
        rotate(num - 1, dir);
    }
    for(int i = 0; i < 4; i++){
        ans += dq[i][0] * (1 << i);
    }
    cout << ans;
    return 0;
}

// rotate 함수를 이용해 배열로도 풀 수 있음.
