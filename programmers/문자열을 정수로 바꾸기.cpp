//
//  문자열을 정수로 바꾸기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0, sign = 1;
    if(s[0] == '+'){
        idx = 1;
    }
    else if (s[0] == '-'){
        idx = 1;
        sign = - 1;
    }
    while(idx < s.length()){
        answer *= 10;
        answer += s[idx++] - '0';
    }
    answer *= sign;
    return answer;
}

/*
 int solution(string s) {
     int answer = stoi(s);
     return answer;
 }
 // 부호처리도 안해도 된다.
 // int → string: to_string(int num);
 */
