//
//  17413 - 단어 뒤집기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string str;
stack<char> s;

int main(){
    FASTIO;
    getline(cin, str);
    int len = (int)str.length();
    int idx = 0;
    while(idx < len){
        if(str[idx] == ' '){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << str[idx++];
        }
        else if(str[idx] == '<'){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << str[idx++];
            while(str[idx] != '>'){
                cout << str[idx++];
            }
            cout << str[idx++];
        }
        else {
            s.push(str[idx++]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}
