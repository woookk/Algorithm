//
//  핸드폰 번호 가리기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/20.
//

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for(int i = 0; i < phone_number.length() - 4; i++){
        phone_number[i] = '*';
    }
    answer = phone_number;
    return answer;
}
