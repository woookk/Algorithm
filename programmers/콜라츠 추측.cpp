//
//  콜라츠 추측.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/21.
//

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int ans = 0;
    long long tmp;
    tmp = num;
    while(tmp > 1){
        if(tmp % 2){
            tmp *= 3;
            tmp += 1;
        }
        else {
            tmp /= 2;
        }
        ans++;
        if(ans == 501) return -1;
    }
    return ans;
}
