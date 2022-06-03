//
//  내적.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int len = a.size();
    for(int i = 0; i < len; i++){
        answer += (a[i] * b[i]);
    }
    return answer;
}
