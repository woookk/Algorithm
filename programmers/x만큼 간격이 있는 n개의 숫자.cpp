//
//  x만큼 간격이 있는 n개의 숫자.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/20.
//

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = 0; i < n; i++){
        answer.push_back(x + x * i);
    }
    return answer;
}
