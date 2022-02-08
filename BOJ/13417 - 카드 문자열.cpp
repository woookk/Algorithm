//
//  13417 - 카드 문자열.cpp
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
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        deque<char> dq;
        for(int i = 0; i < N; i++){
            char tmp;
            cin >> tmp;
            if(dq.empty()) dq.push_back(tmp);
            else if(dq.front() >= tmp) dq.push_front(tmp);
            else if(dq.front() < tmp) dq.push_back(tmp);
        }
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
    return 0;
}
