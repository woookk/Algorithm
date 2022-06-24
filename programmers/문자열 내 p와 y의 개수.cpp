//
//  문자열 내 p와 y의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int cntp = 0, cnty = 0;
    for(auto c: s){
        if(c == 'p' || c == 'P'){
            cntp++;
        }
        else if(c == 'y' || c == 'Y'){
            cnty++;
        }
    }
    answer = (cntp == cnty);
    return answer;
}
