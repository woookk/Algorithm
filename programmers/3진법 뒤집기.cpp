//
//  3진법 뒤집기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tmp;
    while(n){
        tmp.push_back(n % 3);
        n /= 3;
    }
    int mul = 1;
    for(int i = tmp.size() - 1; i >= 0; i--){
        answer += tmp[i] * mul;
        mul *= 3;
    }
    return answer;
}
