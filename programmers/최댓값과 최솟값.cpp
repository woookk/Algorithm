//
//  최댓값과 최솟값.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/28.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string token;
    
    vector<int> numbers;
    for (stringstream str(s); str >> token;) {
        numbers.push_back(stoi(token));
    }
    sort(numbers.begin(), numbers.end());
    
    answer += (to_string(numbers.front()) + " " + to_string(numbers.back()));
    return answer;
}

/**
    문자열 s에는 공백으로 구분된 숫자들이 저장되어 있다. s에 나타나는 숫자 중 최솟값과 최댓갑을 찾아 이를 "(최솟값) (최댓값)" 형태의 문자열을 반환하는 함수를 완성
    
    문자열 파싱해서 최댓값 및 최솟값 구한 후 다시 문자열로 저장
*/
