//
//  Radix_Sort_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/10.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n = 15;
int arr[1000001];
int d = 3;
int p10[3];

int digitNum(int x, int a){
    return (x / p10[a]) % 10;
}

vector<int> l[10];

int main(){
    FASTIO;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    p10[0] = 1;
    for(int i = 1; i < d; i++){
        p10[i] = p10[i - 1] * 10;
    }
    for(int i = 0; i < d; i++){
        for(int j = 0; j < 10; j++) l[j].clear();
        for(int j = 0; j < n; j++){
            l[digitNum(arr[j], i)].push_back(arr[j]);
        }
        int aidx = 0;
        for(int j = 0; j < 10; j++){
            for(auto c : l[j]) arr[aidx++] = c;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
