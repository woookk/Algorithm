//
//  1543 - 문서 검색.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string d, word;
int ans;

int main(){
    FASTIO;
    getline(cin, d);
    getline(cin, word);
    int idx = 0;
    while(idx < d.length()){
        int cnt = 0;
        for(int i = 0; i < word.length(); i++){
            if(d[idx + i] == word[i]) cnt++;
            else {
                idx++;
                break;
            }
        }
        if(cnt == word.length()){
            idx += word.length();
            ans++;
        }
    }
    cout << ans;
    return 0;
}
