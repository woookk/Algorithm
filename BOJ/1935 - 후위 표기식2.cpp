//
//  1935 - 후위 표기식2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string str;


int main(){
    FASTIO
    cin >> N;
    cin >> str;
    vector<int> num(N);
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    int idx = 0;
    stack<double> s;
    while(idx < str.length()){
        if(str[idx] >= 'A' && str[idx] <= 'Z'){
            s.push(num[str[idx] - 'A']);
        }
        else{
            double tmp = s.top();
            s.pop();
            if(str[idx] == '+'){
                tmp += s.top();
            }
            else if(str[idx] == '-'){
                tmp = s.top() - tmp;
            }
            else if(str[idx] == '*'){
                tmp *= s.top();
            }
            else {
                tmp = s.top() / tmp;
            }
            s.pop();
            s.push(tmp);
        }
        idx++;
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";
    return 0;
}
