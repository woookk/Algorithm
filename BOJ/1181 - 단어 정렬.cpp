//
//  1181 - 단어 정렬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;


bool cmp(string& a, string& b){
    int lenA = a.length(), lenB = b.length();
    if(lenA != lenB) {
        return lenA < lenB;
    }
    else {
        return a < b;
    }
}
int main(){
    FASTIO;
    cin >> N;
    vector<string> word(N);
    for(int i = 0; i < N; i++){
        cin >> word[i];
    }
    sort(word.begin(), word.end(), cmp);
    word.erase(unique(word.begin(), word.end()), word.end());
    for(auto v: word){
        cout << v << "\n";
    }
}
