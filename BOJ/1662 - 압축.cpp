//
//  1662 - 압축.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/10.
//

#include <iostream>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int main(){
    FASTIO;
    string S;
    cin >> S;
    stack<pair<char, int>> s;
    int sum = 0;
    for(char c : S){
        if(c == ')'){
            while(!s.empty() && s.top().X != '('){
                sum += s.top().Y;
                s.pop();
            }
            s.pop();
            int repeat = s.top().X - '0';
            s.top().Y = repeat * sum;
            sum = 0;
        }
        else s.push({c, 1});
    }
    int ans = 0;
    while(!s.empty()){
        ans += s.top().Y;
        s.pop();
    }
    cout << ans;
    return 0;
}
