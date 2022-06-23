//
//  정수 제곱근 판별.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/23.
//

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    for(long long i = 1; i * i <= n; i++){
        if(n == i * i){
            answer = (i + 1) * (i + 1);
            return answer;
        }
    }
    return answer;
}
