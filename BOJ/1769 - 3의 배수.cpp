//
//  1769 - 3의 배수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/10.
//

#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string num;
int ans;

int main(){
    FASTIO
    cin >> num;
    while(num.length() > 1){
        int sum = 0;
        for(int i = 0; i < num.length(); i++){
            sum += num[i] - '0';
        }
        num = to_string(sum);
        ans++;
    }
    cout << ans << "\n";
    if((num[0] - '0') % 3 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
