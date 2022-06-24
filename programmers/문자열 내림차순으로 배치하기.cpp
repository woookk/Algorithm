//
//  문자열 내림차순으로 배치하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    return a > b;
}

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), cmp);
    answer = s;
    return answer;
}
