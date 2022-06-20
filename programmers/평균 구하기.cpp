//
//  평균 구하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/20.
//

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto c: arr){
        answer += c;
    }
    answer /= arr.size();
    return answer;
}
