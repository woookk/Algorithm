//
//  약수의 합.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/24.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) answer += i;
    }
    return answer;
}
