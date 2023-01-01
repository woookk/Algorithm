//
//  18115 - 카드 놓기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/31.
//

#include <iostream>
#include <deque>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[1000001];
deque<int> dq;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    for (int i = N, num = 1; i > 0; i--, num++) {
        if (A[i] == 1) {
            dq.push_front(num);
        }
        else if (A[i] == 2) {
            int temp = dq.front();
            dq.pop_front();
            dq.push_front(num);
            dq.push_front(temp);
        }
        else { // A[i] == 3
            dq.push_back(num);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << dq[i] << " ";
    }
    return 0;
}
