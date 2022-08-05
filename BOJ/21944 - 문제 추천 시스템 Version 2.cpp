//
//  21944 - 문제 추천 시스템 Version 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/05.
//

#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int P, L, G;
pair<int, int> prob[100001];

int main(){
    FASTIO
    cin >> N;
    set<int> lv[101];
    set<int> algorithm[101][101];
    for(int i = 0; i < N; i++){
        cin >> P >> L >> G;
        prob[P] = {L, G};
        lv[L].insert(P);
        algorithm[G][L].insert(P);
    }
    cin >> M;
    while(M--){
        string cmd;
        cin >> cmd;
        if(cmd == "recommend"){
            int x;
            cin >> G >> x;
            if(x == 1){
                for(int i = 100; i > 0; i--){
                    if(algorithm[G][i].empty()) continue;
                    cout << *(prev(algorithm[G][i].end())) << "\n";
                    break;
                }
            }
            else {
                for(int i = 1; i <= 100; i++){
                    if(algorithm[G][i].empty()) continue;
                    cout << *algorithm[G][i].begin() << "\n";
                    break;
                }
            }
        }
        else if(cmd == "recommend2"){
            int x;
            cin >> x;
            if(x == 1){
                for(int i = 100; i > 0; i--){
                    if(lv[i].empty()) continue;
                    cout << *(prev(lv[i].end())) << "\n";
                    break;
                }
            }
            else {
                for(int i = 0; i <= 100; i++){
                    if(lv[i].empty()) continue;
                    cout << *lv[i].begin() << "\n";
                    break;
                }
            }
        }
        else if(cmd == "recommend3"){
            int x;
            cin >> x >> L;
            if(x == 1){
                bool isPossible = false;
                for(int i = L; i <= 100; i++){
                    if(lv[i].empty()) continue;
                    cout << *lv[i].begin() << "\n";
                    isPossible = true;
                    break;
                }
                if(!isPossible) cout << -1 << "\n";
            }
            else {
                bool isPossible = false;
                for(int i = L - 1; i > 0; i--){
                    if(lv[i].empty()) continue;
                    cout << *(prev(lv[i].end())) << "\n";
                    isPossible = true;
                    break;
                }
                if(!isPossible) cout << -1 << "\n";
            }
        }
        else if(cmd == "add"){
            cin >> P >> L >> G;
            prob[P] = {L, G};
            lv[L].insert(P);
            algorithm[G][L].insert(P);
        }
        else if(cmd == "solved"){
            cin >> P;
            L = prob[P].first;
            G = prob[P].second;
            lv[L].erase(P);
            algorithm[G][L].erase(P);
        }
    }
    return 0;
}

