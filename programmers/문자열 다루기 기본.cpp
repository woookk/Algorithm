//
//  문자열 다루기 기본.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    if(len != 4 && len != 6){
        answer = false;
    }
    else {
        for(int i = 0; i < len; i++){
            if(s[i] >= '0' && s[i] <= '9') continue;
            else answer = false;
        }
    }
    return answer;
}
