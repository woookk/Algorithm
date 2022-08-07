//
//  2075 - N번째 큰 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/07.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            if(pq.size() < N)
                pq.push(temp);
            else if(pq.top() < temp){
                pq.push(temp);
                pq.pop();
            }
            else {
                continue;
            }
        }
    }
    cout << pq.top();
    return 0;
}
