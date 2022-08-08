//
//  11279 - 최대 힙.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/08.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}
