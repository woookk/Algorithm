//
//  두 정수 사이의 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a > b) swap(a, b);
    for(int i = a; i <= b; i++){
        answer += i;
    }
    return answer;
}
