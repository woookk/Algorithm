//
//  19700 - 수업.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/05.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans;
pair<int, int> arr[500001];
multiset<int> s;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.X == b.X) return a.Y > b.Y;
    return a.X > b.X;
}

int main(){
    FASTIO
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i].X >> arr[i].Y;
    }
    sort(arr, arr + N, cmp);
    for(int i = 0; i < N; i++){
        auto it = s.upper_bound(-arr[i].Y);
        if(it == s.end()) s.insert(-1);
        else {
            int k = (*it) - 1;
            s.erase(it);
            s.insert(k);
        }
    }
    cout << s.size();
    return 0;
}
