//
//  두 큐 합 같게 만들기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/24.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> scores;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int numberOfQuestions = choices.size();
    
    for (int i = 0; i < numberOfQuestions; i++) {
        if (choices[i] <= 3) scores[survey[i][0]] += 4 - choices[i];
        else scores[survey[i][1]] += choices[i] - 4;
    }
                    
    if (scores['R'] >= scores['T']) answer += "R";
    else answer += "T";
                    
    if (scores['C'] >= scores['F']) answer += "C";
    else answer += "F";
                    
    if (scores['J'] >= scores['M']) answer += "J";
    else answer += "M";
                    
    if (scores['A'] >= scores['N']) answer += "A";
    else answer += "N";
    
    return answer;
}

/*
    카카오 성격 유형 검사지
    4개의 지표로 성격 유형을 구분하고, 성격은 각 지표에서 두 유형 중 하나로 결정
    지표 번호 (1 ~ 4), R / T, C / F, J / M, A / N 존재
    
    검사지에는 총 n개의 질문이 있고, 각 질문에는 7개의 선택지가 존재
    각 질문은 1가지 지표로 성격 유형 점수를 판단
    동의, 비동의에 들어가는 성격 유형은 질문에 따라서 다르게 정해진다.
    
    검사 결과는 모든 질문의 성격 유형 점수를 더하여 각 지표에서 더 높은 점수를 받은 성격 유형이 검사자의 성격 유형이라고 판단.
    하나의 지표에서 각 성격 유형 점수가 같으면, 두 성격 유형 중 사전 순으로 빠른 성격 유형을 검사자의 성격 유형이라고 판단
    
    key로 value를 빠르게 찾을 수 있는 Hash, Map 등을 사용해도 되고 배열로 처리하거나 적절하게 if문 넣어서 계산을 잘 해줘도 상관 없다.
 
    unordered_map 이용해서 풀이 진행
*/
