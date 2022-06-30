//
//  [1차] 다트 게임.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/27.
//

#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score(3);
    int tmp = 0, idx = 0;
    for(int i = 0; i < dartResult.length(); i++){
        if(dartResult[i] == '0' && dartResult[i - 1] == '1'){
            tmp = tmp * 10 + dartResult[i] - '0';
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            tmp = dartResult[i] - '0';
        }
        else if(dartResult[i] == '*'){
            if(idx == 1){
                score[idx - 1] *= 2;
            }
            else {
                score[idx - 1] *= 2;
                score[idx - 2] *= 2;
            }
        }
        else if(dartResult[i] == '#'){
            score[idx - 1] *= -1;
        }
        else {
            if(dartResult[i] == 'S') score[idx++] = tmp;
            else if(dartResult[i] == 'D') score[idx++] = tmp * tmp;
            else {
                score[idx++] = tmp * tmp * tmp;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        answer += score[i];
    }
    return answer;
}
