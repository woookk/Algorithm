//
//  문자열 압축.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/30.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int len = s.length();
    for(int i = 1; i <= len / 2; i++){
        int sum = s.length(), cnt = 0;
        for(int j = i; j < len; j += i){
            string pre = "";
            string cur = "";
            for(int k = 0; k < i; k++){
                pre.push_back(s[j - i + k]);
                cur.push_back(s[j + k]);
            }
            if(pre.compare(cur) == 0){
                sum -= cur.length();
                cnt++;
            }
            else {
                if(cnt != 0){
                    string tmp = to_string(cnt + 1);
                    sum += tmp.length();
                }
                cnt = 0;
            }
        }
        if(cnt != 0){
            string tmp = to_string(cnt + 1);
            sum += tmp.length();
        }
        answer = min(answer, sum);
    }
    if(answer == 1001) answer = 1;
    return answer;
}
