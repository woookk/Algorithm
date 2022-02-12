//
//  6603 - 로또.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/13.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int S[13];
int lotto[6];
int k;

void combination(int start, int depth){
    if(depth == 6){
        for(int i = 0; i < 6; i++){
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i < k; i++){
        lotto[depth] = S[i];
        combination(i+1, depth+1);
    }
}

int main(){
    FASTIO;
    while(1){
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++){
            cin >> S[i];
        }
        combination(0, 0);
        cout << "\n";
    }
    return 0;
}
