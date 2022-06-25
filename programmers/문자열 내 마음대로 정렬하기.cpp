//
//  문자열 내 마음대로 정렬하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    for(int i = 0; i < strings.size() - 1; i++){
        for(int j = i + 1; j < strings.size(); j++){
            string tmp;
            if(strings[i][n] > strings[j][n]) {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
            else if (strings[i][n] == strings[j][n]){
                if(strings[i] > strings[j]){
                    tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
                }
            }
        }
    }
    answer = strings;
    return answer;
}
