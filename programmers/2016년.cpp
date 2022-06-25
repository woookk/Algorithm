//
//  2016년.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weekday[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    int day = b - 1;
    while(a){
        day += days[--a];
    }
    return weekday[day % 7];
}
