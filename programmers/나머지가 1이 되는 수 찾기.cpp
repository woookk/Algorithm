//
//  나머지가 1이 되는 수 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for(int i = 2; i <= n - 1; i++){
        if((n - 1) % i == 0) return i;
    }
    return -1;
}
