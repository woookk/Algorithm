//
//  정수 내림차순으로 배치하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/24.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool cmp(int a, int b){
    return a > b;
}
long long solution(long long n) {
    long long answer = 0;
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        answer *= 10;
        answer += v[i];
    }
    return answer;
}
