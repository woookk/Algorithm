//
//  1781 - 컵라면.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans;

int main(){
    FASTIO
    cin >> N;
    vector<pair<int, int>> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i].X >> arr[i].Y;
    }
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        if(pq.size() < arr[i].X){
            pq.push(arr[i].Y);
        }
        else {
            if(pq.top() < arr[i].Y){
                pq.pop();
                pq.push(arr[i].Y);
            }
        }
    }
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}
