//
//  부족한 금액 계산하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    for(int i = 1; i <= count; i++){
        sum += price * i;
    }
    if(money >= sum) answer = 0;
    else {
        answer = sum - money;
    }
    return answer;
}
