//
//  1620 - 나는야 포켓몬 마스터 이다솜.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/27.
//

#include <iostream>
#include <cctype>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
unordered_map<string, int> sToi;
string iTos[100005];

int main(){
    FASTIO
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> iTos[i];
        sToi[iTos[i]] = i;
    }
    while(M--){
        string temp;
        cin >> temp;
        if(isdigit(temp[0]))
            cout << iTos[stoi(temp)] << "\n";
        else
            cout << sToi[temp] << "\n";
    }
    return 0;
}
