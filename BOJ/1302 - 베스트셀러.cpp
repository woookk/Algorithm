//
//  1302 - 베스트셀러.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string ans;
vector<string> v;

int main(){
    FASTIO
    cin >> N;
    while(N--){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int cnt = 1, MX = 0;
    ans = v[0];
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] == v[i + 1]) {
            cnt++;
            if(cnt > MX){
                ans = v[i];
                MX = cnt;
            }
        }
        else {
            cnt = 1;
        }
    }
    cout << ans;
    return 0;
}
