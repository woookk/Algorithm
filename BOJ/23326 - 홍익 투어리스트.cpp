//
//  23326 - 홍익 투어리스트.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/05.
//

#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, Q, cur;

int main(){
    FASTIO
    cin >> N >> Q;
    set<int> s;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1) s.insert(i);
    }
    while(Q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int i;
            cin >> i;
            if(s.find(i - 1) != s.end()){
                s.erase(i - 1);
            }
            else {
                s.insert(i - 1);
            }
        }
        else if(cmd == 2){
            int x;
            cin >> x;
            cur = (cur + x) % N;
        }
        else {
            if(s.empty()){
                cout << -1 << "\n";
                continue;
            }
            auto it = s.lower_bound(cur);
            if(it != s.end()){
                cout << *it - cur << "\n";
            }
            else {
                cout << N - cur + *s.begin() << "\n";
            }
        }
    }
    return 0;
}
