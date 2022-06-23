//
//  이상한 문자 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/24.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int pos = 0;
    string delim = " ";
    string token;
    while( (pos = s.find(delim)) != string::npos){
        token = s.substr(0, pos);
        s.erase(0, pos + delim.length());
        for(int i = 0; i < token.length(); i++){
            if(i % 2){
                answer += tolower(token[i]);
            }
            else {
                answer += toupper(token[i]);
            }
        }
        answer.push_back(' ');
    }
    token = s;
    for(int i = 0; i < token.length(); i++){
        if(i % 2){
                answer += tolower(token[i]);
        }
        else {
            answer += toupper(token[i]);
        }
    }
    return answer;
}
