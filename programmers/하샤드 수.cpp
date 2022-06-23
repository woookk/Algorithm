//
//  하샤드 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/20.
//

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum, d;
    sum = 0; d = 1;
    while(x / d){
        sum += (x / d) % 10;
        d *= 10;
    }
    answer = (x % sum == 0);
    return answer;
}
