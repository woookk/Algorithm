//
//  1213 - 팰린드롬 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string name;
int cnt[26];
int mid = -1;

bool isPossible(){
    for(auto c: name){
        cnt[c - 'A']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2 != 0){
            ans++;
            mid = i;
        }
    }
    return ans < 2;
}

int main(){
    FASTIO
    cin >> name;
    if(!isPossible()) cout << "I'm Sorry Hansoo\n";
    else {
        string ans="";
        string temp="";
        for(int i = 0; i <26; i++){
            if(cnt[i] > 0){
                for(int j = 0; j < cnt[i] / 2; j++){
                    ans += i + 'A';
                }
            }
        }
        temp = ans;
        reverse(temp.begin(), temp.end());
        if(mid != -1){
            ans += mid + 'A';
        }
        ans += temp;
        cout << ans << "\n";
    }
    return 0;
}
