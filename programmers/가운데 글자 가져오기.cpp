//
//  가운데 글자 가져오기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    if(len % 2){
        answer.push_back(s[len / 2]);
    }
    else {
        answer.push_back(s[len / 2 - 1]);
        answer.push_back(s[len / 2]);
    }
    return answer;
}
