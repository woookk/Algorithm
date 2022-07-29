//
//  19583 - 싸이버개강총회.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/29.
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int S, E, Q;
string s, e, q;
string str, name;

int minute(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int main(){
    FASTIO
    cin >> s >> e >> q;
    S = minute(s);
    E = minute(e);
    Q = minute(q);
    
    unordered_set<string> st;
    unordered_set<string> ans;
    
    while(cin.eof() == false){
        cin >> str >> name;
        int temp = minute(str);
        
        if(temp <= S){
            st.insert(name);
        }
        else if(E <= temp && temp <= Q){
            if(st.find(name) != st.end()){
                ans.insert(name);
            }
        }
    }
    
    cout << ans.size();
    return 0;
}
