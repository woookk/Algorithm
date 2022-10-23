//
//  EquivalenceN.cpp
//  DS
//
//  Created by 민병욱 on 2022/04/23.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m;

vector<int> Map[1000];

int Stack[10000];
int SP;

void Push(int x){ //Overflow 예외처리 X
    Stack[SP++] = x;
    return;
}

int Pop(){
    return Stack[--SP];
}

int IsEmpty(){
    return (SP == 0);
}

void SetLink(int x, int y){
    Map[x].push_back(y);
    return;
}

int LastForward[1000];

int NextForward(int x){
    LastForward[x]++;
    if (LastForward[x] < Map[x].size())
        return Map[x][LastForward[x]];
    else
        return -1;
}

int Vis[1000];
int LastStart;

int IsMarked(int x){
    return Vis[x];
}

int NextStart(){
    LastStart++;
    while (LastStart <= n){
        if (IsMarked(LastStart) == 0)
            return LastStart;
        else
            LastStart++;
    }
    return -1;
}

void Mark(int x){
    Vis[x] = 1;
}

int main(){
    FASTIO;
    int i, x, y, cur, s;
    for(i = 0; i < 1000; i++){ //initailization
        LastForward[i] = -1;
    }
    cin >> n >> m;
    for (i = 0; i < m; i++){
        cin >> x >> y;
        SetLink(x, y);
        SetLink(y, x);
    }
    while ((cur = NextStart()) != -1) {
        cout << cur << " ";
        Mark(cur);
        while(1) {
            if ((s = NextForward(cur)) != -1){
                if(IsMarked(s) == 0){
                    cout << s << " ";
                    Mark(s);
                    Push(cur);
                    cur = s;
                }
                else {
                    ;
                }
            }
            else {
                if (IsEmpty() == 1){
                    break;
                }
                else {
                    cur = Pop();
                }
            }
        }
        cout << "\n";
    }
        
    return 0;
}

