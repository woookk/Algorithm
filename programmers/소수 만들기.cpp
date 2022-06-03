//
//  소수 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <vector>
#include <iostream>
using namespace std;

bool prime[3000];

void sieve(){
    for(int i = 2; i < 3000; i++){
        prime[i] = true;
    }
    for(int i = 2; i * i < 3000; i++){
        if(prime[i] == 0) continue;
        for(int j = i * i; j < 3000; j += i){
            if(prime[j] == 0) continue;
            else prime[j] = 0;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    int len = nums.size();
    sieve();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            for(int k = j + 1; k < len; k++){
                if(prime[nums[i] + nums[j] + nums[k]]) answer++;
            }
        }
    }
    return answer;
}
