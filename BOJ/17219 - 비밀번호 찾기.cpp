//
//  17219 - 비밀번호 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/28.
//

#include <iostream>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;

int main(){
    FASTIO
    cin >> N >> M;
    unordered_map<string, string> note;
    while(N--){
        string url, pw;
        cin >> url >> pw;
        note[url] = pw;
    }
    while(M--){
        string url;
        cin >> url;
        cout << note[url] << "\n";
    }
    return 0;
}
