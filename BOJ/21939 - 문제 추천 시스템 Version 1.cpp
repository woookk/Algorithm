//
//  21939 - 문제 추천 시스템 Version 1.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/04.
//

#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, P, L;
int prob[100001];

int main(){
    FASTIO
    cin >> N;
    set<int> s[102];
    for(int i = 0; i < N; i++){
        cin >> P >> L;
        prob[P] = L;
        s[L].insert(P);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            cin >> P >> L;
            prob[P] = L;
            s[L].insert(P);
        }
        else if(cmd == "solved"){
            cin >> P;
            s[prob[P]].erase(P);
        }
        else if(cmd == "recommend"){
            int x;
            cin >> x;
            if(x == 1){
                for(int i = 100; i > 0; i--){
                    if(s[i].empty()) continue;
                    cout << *(prev(s[i].end())) << "\n";
                    break;
                }
            }
            else {
                for(int i = 1; i < 101; i++){
                    if(s[i].empty()) continue;
                    cout << *(s[i].begin()) << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
