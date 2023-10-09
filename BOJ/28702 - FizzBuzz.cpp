//
//  28702 - FizzBuzz.cpp
//  cpp
//
//  Created by 민병욱 on 2023/10/05.
//

#include <iostream>
#include <string>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string s;
int ans;

int main() {
    FASTIO
    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (s.compare("Fizz") == 0 || s.compare("Buzz") == 0 || s.compare("FizzBuzz") == 0) {
            continue;
        }
        ans = stoi(s) + (3 - i);
    }
    if (ans % 3 == 0 && ans % 5 == 0) {
        cout << "FizzBuzz";
    }
    else if (ans % 3 == 0) {
        cout << "Fizz";
    }
    else if (ans % 5 == 0) {
        cout << "Buzz";
    }
    else {
        cout << ans;
    }
    return 0;
}

/*
 FizzBuzz 문제는 i = 1, 2, ...에 대해서 규칙에 따라 문자열을 한 줄에 하나씩 출력하는 문제
 - i가 3의 배수 && 5의 배수 "FizzBuzz"
 - i가 3의 배수 && !5의 배수 "Fizz"
 - i가 !3의 배수 && 5의 배수 "Buzz"
 - i가 !3의 배수 && !5의 배수 i 그대로 출력
 
 
 */
