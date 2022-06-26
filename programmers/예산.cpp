//
//  예산.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++){
        if(budget - d[i] >= 0){
            answer++;
            budget -= d[i];
        }
        else {
            break;
        }
    }
    return answer;
}
