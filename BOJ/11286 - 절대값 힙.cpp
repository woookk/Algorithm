//
//  11286 - 절대값 힙.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/06.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

class cmp {
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int N;

int main(){
    FASTIO
    priority_queue<int, vector<int>, cmp> pq;
    cin >> N;
    while(N--){
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
