//
//  약수의 개수와 덧셈.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i < right + 1; i++){
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) cnt++;
        }
        if(cnt % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}
