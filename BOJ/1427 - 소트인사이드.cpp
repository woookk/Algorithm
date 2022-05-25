//
//  1427 - 소트인사이드.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/25.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string num;

bool cmp(char a, char b){
    return a > b;
}
int main(){
    FASTIO;
    cin >> num;
    sort(num.begin(), num.end(), cmp);
    cout << num;
    return 0;
}
