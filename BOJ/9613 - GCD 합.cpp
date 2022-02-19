//
//  9613 - GCD 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/19.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int GCD(int a, int b){
    while(b!=0){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int n;
long long sum;
int ans[2];
int num[101];

void combination(int start, int depth){
    if(depth == 2){
        sum += GCD(ans[0], ans[1]);
        return;
    }
    for(int i = start; i < n; i++){
        ans[depth] = num[i];
        combination(i+1, depth+1);
    }
}

int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }
        sum = 0;
        combination(0, 0);
        cout << sum << "\n";
    }
    return 0;
}
