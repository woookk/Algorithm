//
//  두 개 뽑아서 더하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> tmp;
    for(int i = 0; i < numbers.size() - 1; i++){
        for(int j = i + 1; j < numbers.size(); j++){
            tmp.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(tmp.begin(), tmp.end());
    answer.push_back(tmp[0]);
    for(int i = 1; i < tmp.size(); i++){
        if(tmp[i - 1] == tmp[i]) continue;
        answer.push_back(tmp[i]);
    }
    return answer;
}
