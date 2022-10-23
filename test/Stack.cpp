//
//  Stack.cpp
//  DS
//
//  Created by 민병욱 on 2022/04/15.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define N 1000

int Stack[N];
int sp;

int init(){
    sp = 0;
    return 0;
}

int isEmpty(){
    return sp == 0;
}

int Push(int x){
    Stack[sp++] = x;
    return 0;
}

int Pop(){
    return Stack[--sp];
}

int main(){
    FASTIO;
    init();
    while(1){
        int tmp;
        cin >> tmp;
        if(tmp == 0) break;
        Push(tmp);
    }
    while(sp){
        int tmp = Pop();
        cout << tmp << " ";
    }
    return 0;
}
