//
//  자연수 뒤집어 배열로 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/24.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(n){
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}
