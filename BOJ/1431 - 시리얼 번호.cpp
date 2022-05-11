//
//  1431 - 시리얼 번호.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/11.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string serial_num[51];

bool cmp(string a, string b){
    int lenA = a.length(), lenB = b.length();
    int sumA = 0, sumB = 0;
    if(lenA != lenB) return lenA < lenB;
    else {
        for(int i = 0; i < lenA; i++){
            if(a[i] >= '0' && a[i] <= '9') sumA += (a[i] - '0');
            if(b[i] >= '0' && b[i] <= '9') sumB += (b[i] - '0');
        }
        if(sumA != sumB) return sumA < sumB;
        return a < b;
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> serial_num[i];
    }
    sort(serial_num, serial_num + N, cmp);
    for(int i = 0; i < N; i++){
        cout << serial_num[i] << "\n";
    }
}
