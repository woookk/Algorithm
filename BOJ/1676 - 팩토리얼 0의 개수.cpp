//
//  1676 - 팩토리얼 0의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/07.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int cnt2, cnt5;

int main(){
    FASTIO
    cin >> N;
    for(int i = N; i >= 1; i--){
        int tmp = i;
        while(1){
            if(tmp % 2 == 0){
                tmp /= 2;
                cnt2++;
            }
            else if(tmp % 5 == 0){
                tmp /= 5;
                cnt5++;
            }
            else {
                break;
            }
        }
    }
    cout << min(cnt2, cnt5);
    return 0;
}
