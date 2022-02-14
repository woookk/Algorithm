//
//  1759 - 암호 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int L, C;
char password[16];
char alpha[16];

void combination(int start, int depth){
    if(depth == L){
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < L; i++){
            if(password[i]=='a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') cnt1++;
            else cnt2++; 
        }
        if(cnt1 && cnt2 >= 2){
            for(int i = 0; i < L; i++){
                cout << password[i];
            }
            cout << "\n";
        }
        return;
    }
    for(int i = start; i < C; i++){
        password[depth] = alpha[i];
        combination(i+1, depth+1);
    }
}

int main(){
    FASTIO;
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> alpha[i];
    }
    sort(alpha, alpha + C);
    combination(0, 0);
    return 0;
}
