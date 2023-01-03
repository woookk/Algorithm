//
//  2696 - 중앙값 구하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/03.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;

int main() {
    FASTIO
    cin >> TC;
    while(TC--) {
        int M;
        cin >> M;
        
        priority_queue<int, vector<int>, less<int>> minq;
        priority_queue<int, vector<int>, greater<int>> maxq;
        vector<int> ans;
        
        for (int i = 1; i <= M; i++) {
            int num;
            cin >> num;
            
            if (i == 1) {
                minq.push(num);
                ans.push_back(minq.top());
            }
            else if (i % 2 == 1) {
                if (minq.top() >= num) {
                    minq.push(num);
                }
                else if (minq.top() < num && maxq.top() > num) {
                    minq.push(num);
                }
                else {
                    int temp = maxq.top();
                    maxq.pop();
                    minq.push(temp);
                    maxq.push(num);
                }
                ans.push_back(minq.top());
            }
            else {
                if (minq.top() > num) {
                    int temp = minq.top();
                    minq.pop();
                    minq.push(num);
                    maxq.push(temp);
                }
                else {
                    maxq.push(num);
                }
            }
        }
        cout << ans.size() << "\n";
        
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0 && i % 10 == 0) {
                cout << '\n';
            }
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
