//
//  16916 - 부분 문자열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string s, p;

vector<int> makeTable(){
    vector<int> table(p.length());
    int j = 0;
    for (int i = 1; i < p.length(); i++) {
            while (p[i] != p[j] && j > 0) {
                j = table[--j];
            }
            if (p[i] == p[j]) {
                table[i] = ++j;
            }
        }
        return table;
}

int kmp(vector<int> &table){
    int j = 0;
    for(int i = 0; i < s.length(); i++){
        while(s[i] != p[j] && j > 0) {
            j = table[--j];
        }
        if(s[i] == p[j]){
            if(++j == p.length()){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    FASTIO
    cin >> s >> p;
    vector<int> table = makeTable();
    
    cout << kmp(table);
    return 0;
}
