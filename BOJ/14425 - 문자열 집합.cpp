//
//  14425 - 문자열 집합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/29.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, ans;
unordered_map<string, int> set;
string s;

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        set.insert({s, 1});
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        ans += set[s];
    }
    cout << ans;
    return 0;
}
