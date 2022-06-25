//
//  서울에서 김서방 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string Kim = "Kim";
    int x;
    for(int i = 0; i < seoul.size(); i++){
        if(Kim.compare(seoul[i]) == 0) {
            x = i;
        }
    }
    answer = "김서방은 " + to_string(x) + "에 있다";
    return answer;
}
