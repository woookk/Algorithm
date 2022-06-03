//
//  없는 숫자 더하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    int len = numbers.size();
    for(int i = 0; i < len; i++){
        answer -= numbers[i];
    }
    return answer;
}
