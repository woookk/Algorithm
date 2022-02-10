//
//  2812 - 크게 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/10.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    int N, K;
    cin >> N >> K;
    string num;
    cin >> num;
    stack<int> s;
    int cnt = 0;
    for(auto c : num){
        int tmp = c -'0';
        while(!s.empty() && s.top() < tmp && cnt < K){
            s.pop();
            cnt++;
        }
        s.push(tmp);
    }
    while(cnt < K){
        s.pop();
        cnt++;
    }
    vector<int> ans;
    for(int i = 0; i < N-K; i++){
        ans.push_back(s.top());
        s.pop();
    }
    for(int i = (int)ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }
}
