//
//  시저 암호.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ') answer.push_back(' ');
        else if(s[i] >= 'a' && s[i] <= 'z') {
            answer.push_back('a' + (s[i] - 'a' + n) % 26);
        }
        else { // A ~ Z
            answer.push_back('A' + (s[i] - 'A' + n) % 26);
        }
    }
    return answer;
}
