//
//  1744 - 수 묶기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
int num;

vector<int> p, n;

bool cmp(int a, int b){
    return a > b;
}

void seqSum(vector<int> v){
    while (1 < v.size()) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if (v.size())
        ans += v[0];
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == 1) ans++;
        else if (num > 0){
            p.push_back(num);
        }
        else {
            n.push_back(num);
        }

    }
    sort(p.begin(), p.end());
    sort(n.begin(), n.end(), cmp);
    seqSum(p);
    seqSum(n);
    cout << ans;
    return 0;
}
