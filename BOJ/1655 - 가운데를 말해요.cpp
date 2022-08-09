//
//  1655 - 가운데를 말해요.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/09.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    priority_queue<int> mxq;
    priority_queue<int, vector<int>, greater<int>> mnq;
    while(N--){
        int tmp;
        cin >> tmp;
        if(mxq.size() > mnq.size()) mnq.push(tmp);
        else mxq.push(tmp);
        
        if(!mxq.empty() && !mnq.empty()){
            if(mxq.top() > mnq.top()){
                int mxval = mxq.top();
                mxq.pop();
                int mnval = mnq.top();
                mnq.pop();
                mxq.push(mnval);
                mnq.push(mxval);
            }
        }
        cout << mxq.top() << "\n";
    }
    return 0;
}
