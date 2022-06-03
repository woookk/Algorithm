//
//  5525 - IOIOI.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;
string IOIOI;

int main(){
    FASTIO
    cin >> N >> M;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < M; i++){
        int len = 0;
        if(s[i] == 'O') continue;
        else {
            while(s[i + 1] == 'O' && s[i + 2] == 'I'){
                len++;
                if(len == N){
                    len--;
                    ans++;
                }
                i += 2;
            }
            len = 0;
        }
    }
    cout << ans;
    return 0;
}
