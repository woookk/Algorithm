//
//  vector_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/14.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO
    vector<int> v1(10, -1);
    vector<int> v2 = v1;
    vector<int> &v3 = v1;
    for(int i = 0; i < 10; i++){
        v1[i] = i;
    }
    for(auto &c: v1){
        cout << c << " ";
    }
    cout << "\n";
    for(auto &c: v2){
        cout << c << " ";
    }
    cout << "\n";
    for(auto &c: v3){
        cout << c << " ";
    }
    return 0;
}
