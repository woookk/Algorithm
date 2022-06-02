//
//  숫자 문자열과 영단어.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/02.
//

#include <string>
#include <vector>

using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            answer *= 10;
            answer += s[i] - '0';
            continue;
        }
        else {
            for(int j = 0; j < 10; j++){
                int cnt = 0;
                for(int k = 0; k < num[j].length(); k++){
                    if(s[i + k] == num[j][k]) cnt++;
                }
                if(cnt == num[j].length()){
                    answer *= 10;
                    answer += j;
                    break;
                }
            }
        }
    }
    return answer;
}
