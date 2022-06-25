//
//  나누어 떨어지는 숫자 배열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0) answer.push_back(arr[i]);
    }
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
